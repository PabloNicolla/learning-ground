import { createEntityAdapter, createSelector, createSlice, EntityState, nanoid, PayloadAction } from '@reduxjs/toolkit'
import { client } from '@/api/client'

import { RootState } from '@/app/store'
import { createAppAsyncThunk } from '@/app/withTypes'
import { logout } from '../auth/authSlice'
import { AppStartListening } from '@/app/listenerMiddleware'
import { apiSlice } from '../api/apiSlice'

/*
We've already seen that we can pass an argument into a thunk action creator when we dispatch it, like dispatch(addPost(newPost)). For createAsyncThunk specifically, you can only pass in one argument, and whatever we pass in becomes the first argument of the payload creation callback. If we don't actually pass anything in, then that argument becomes undefined.

The second argument to our payload creator is a thunkAPI object containing several useful functions and pieces of information:

    dispatch and getState: the actual dispatch and getState methods from our Redux store. You can use these inside the thunk to dispatch more actions, or get the latest Redux store state (such as reading an updated value after another action is dispatched).
    extra: the "extra argument" that can be passed into the thunk middleware when creating the store. This is typically some kind of API wrapper, such as a set of functions that know how to make API calls to your application's server and return data, so that your thunks don't have to have all the URLs and query logic directly inside.
    requestId: a unique random ID value for this thunk call. Useful for tracking status of an individual request.
    signal: An AbortController.signal function that can be used to cancel an in-progress request.
    rejectWithValue: a utility that helps customize the contents of a rejected action if the thunk receives an error.
*/

export const addNewPost = createAppAsyncThunk(
  'posts/addNewPost',
  // The payload creator receives the partial `{title, content, user}` object
  async (initialPost: NewPost) => {
    // We send the initial data to the fake API server
    const response = await client.post<Post>('/fakeApi/posts', initialPost)
    // The response includes the complete post object, including unique ID
    return response.data
  },
)

export const fetchPosts = createAppAsyncThunk(
  'posts/fetchPosts',
  async () => {
    const response = await client.get<Post[]>('/fakeApi/posts')
    return response.data
  },
  {
    // createAsyncThunk accepts an optional condition callback we can use to do that check.
    // If provided, it runs at the start of the thunk call, and it will cancel the entire thunk if condition returns false.
    condition(arg, thunkApi) {
      const postsStatus = selectPostsStatus(thunkApi.getState())
      if (postsStatus !== 'idle') {
        return false
      }
    },
  },
)

export interface Reactions {
  thumbsUp: number
  tada: number
  heart: number
  rocket: number
  eyes: number
}

export type ReactionName = keyof Reactions

// Define a TS type for the data we'll be using
export interface Post {
  id: string
  title: string
  content: string
  user: string
  date: string
  reactions: Reactions
}

export type PostUpdate = Pick<Post, 'id' | 'title' | 'content'>
export type NewPost = Pick<Post, 'title' | 'content' | 'user'>

const initialReactions: Reactions = {
  thumbsUp: 0,
  tada: 0,
  heart: 0,
  rocket: 0,
  eyes: 0,
}

interface PostsState extends EntityState<Post, string> {
  status: 'idle' | 'pending' | 'succeeded' | 'rejected'
  error: string | null
}

// Managing Normalized State with createEntityAdapter
const postsAdapter = createEntityAdapter<Post>({
  // Sort in descending date order (Optional sortComparer)
  sortComparer: (a, b) => b.date.localeCompare(a.date),
})

// getInitialState function that generates an empty {ids: [], entities: {}} object. You can pass in more fields to getInitialState, and those will be merged in.
const initialState: PostsState = postsAdapter.getInitialState({
  status: 'idle',
  error: null,
})

const postsSlice = createSlice({
  name: 'posts',
  initialState,
  reducers: {
    // Declare a "case reducer" named `postAdded`.
    // The type of `action.payload` will be a `Post` object.
    /*
    postAdded: {
      reducer(state, action: PayloadAction<Post>) {
        // "Mutate" the existing state array, which is
        // safe to do here because `createSlice` uses Immer inside.
        state.posts.push(action.payload)
      },
      prepare(title: string, content: string, userId: string) {
        return {
          payload: {
            id: nanoid(),
            date: new Date().toISOString(),
            reactions: initialReactions,
            title,
            content,
            user: userId,
          },
        }
      },
    },
    */

    postUpdated(state, action: PayloadAction<PostUpdate>) {
      const { id, title, content } = action.payload
      // const existingPost = state.entities[id]
      // if (existingPost) {
      //   existingPost.title = title
      //   existingPost.content = content
      // }
      postsAdapter.updateOne(state, { id, changes: { title, content } })
    },

    reactionAdded(state, action: PayloadAction<{ postId: string; reaction: ReactionName }>) {
      const { postId, reaction } = action.payload
      const existingPost = state.entities[postId]
      if (existingPost) {
        existingPost.reactions[reaction]++
      }
    },
  },
  selectors: {
    // Note that these selectors are given just the `PostsState`
    // as an argument, not the entire `RootState`
    /*
    selectAllPosts: (postsState) => postsState.posts,
    selectPostById: (postsState, postId: string) => {
      return postsState.posts.find((post) => post.id === postId)
    },
    */
    selectPostsError: (postState) => postState.error,
    selectPostsStatus: (postState) => postState.status,
    //
    //
    //
    /* 
    selectPostsByUser: (postsState, userId: string) => {
      const allPosts = selectAllPosts({ posts: postsState })
      // ❌ WRONG - this _always_ creates a new array reference!
      // Causing components to re-render even when nothing changed
      return allPosts.filter((post) => post.user === userId)
    },
    */
  },

  extraReducers: (builder) => {
    /*
    builder.addCase(actionCreator, caseReducer): listens for one specific action type
    builder.addMatcher(matcherFunction, caseReducer): listens for any one of multiple action types, using a Redux Toolkit "matcher" function for comparing action objects
    builder.addDefaultCase(caseReducer): adds a case reducer that runs if nothing else in this slice matched the action (equivalent to a default case inside of a switch).
    You can chain these together, like builder.addCase().addCase().addMatcher().addDefaultCase().
    If multiple matchers match the action, they will run in the order they were defined.
    */
    // Pass the action creator to `builder.addCase()`
    builder
      //
      // Intercept action even from other slices. (Global Action listener)
      // Useful for cascade effects
      // `many reducers respond to the same dispatched action.`
      //
      .addCase(logout.fulfilled, (state) => {
        // Clear out the list of posts whenever the user logs out
        // Immer lets us update state in two ways: either mutating the existing state value, or returning a new result
        // BUT NEVER DO BOTH
        return initialState
      })
      //
      // Thunk case handling
      // Can be removed if defined inside reducers: ... (However, syntax is not good)
      //
      .addCase(fetchPosts.pending, (state, action) => {
        state.status = 'pending'
      })
      .addCase(fetchPosts.fulfilled, (state, action) => {
        state.status = 'succeeded'
        // Save the fetched posts into state
        postsAdapter.setAll(state, action.payload)
      })
      .addCase(fetchPosts.rejected, (state, action) => {
        state.status = 'rejected'
        state.error = action.error.message ?? 'Unknown Error'
      })
      //
      // Add post from data fetched by API
      //
      .addCase(addNewPost.fulfilled, postsAdapter.addOne)
  },
})

// Export the auto-generated action creator with the same name
export const { /*postAdded,*/ postUpdated, reactionAdded } = postsSlice.actions

export default postsSlice.reducer

export const { selectPostsError, selectPostsStatus } = postsSlice.selectors

// Export the customized selectors for this adapter using `getSelectors`
export const {
  selectAll: selectAllPosts,
  selectById: selectPostById,
  selectIds: selectPostIds,
  // Pass in a selector that returns the posts slice of state
} = postsAdapter.getSelectors((state: RootState) => state.posts)

/*
Reselect is a library for creating memoized selector functions, and was specifically designed to be used with Redux. It has a createSelector function that generates memoized selectors that will only recalculate results when the inputs change. Redux Toolkit exports the createSelector function, so we already have it available.
If we try calling selectPostsByUser multiple times, it will only re-run the output selector if either posts or userId has changed:
Selectors only need to be memoized if they create and return new object or array references, or if the calculation logic is "expensive".
*/
export const selectPostsByUser = createSelector(
  // Pass in one or more "input selectors"
  [
    // we can pass in an existing selector function that
    // reads something from the root `state` and returns it
    selectAllPosts,
    // and another function that extracts one of the arguments
    // and passes that onward
    (state: RootState, userId: string) => userId,
  ],
  // the output function gets those values as its arguments,
  // and will run when either input value changes
  (posts, userId) => posts.filter((post) => post.user === userId),
)

// export const selectAllPosts = (state: RootState) => state.posts
// export const selectPostById = (state: RootState, postId: string) => state.posts.find((post) => post.id === postId)

//
// Middleware listener
//

export const addPostsListeners = (startAppListening: AppStartListening) => {
  startAppListening({
    matcher: apiSlice.endpoints.addNewPost.matchFulfilled,
    effect: async (action, listenerApi) => {
      const { toast } = await import('react-tiny-toast')

      const toastId = toast.show('New post added!', {
        variant: 'success',
        position: 'bottom-right',
        pause: true,
      })

      await listenerApi.delay(5000)
      toast.remove(toastId)
    },
    //matcher
    //predicate
  })
}
