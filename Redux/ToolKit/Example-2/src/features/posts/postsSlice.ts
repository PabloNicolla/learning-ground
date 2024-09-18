import { createSlice, nanoid, PayloadAction } from '@reduxjs/toolkit'
import { client } from '@/api/client'

// import { RootState } from '@/app/store'
import { createAppAsyncThunk } from '@/app/withTypes'

import { userLoggedOut } from '@/features/auth/authSlice'

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

type PostUpdate = Pick<Post, 'id' | 'title' | 'content'>
type NewPost = Pick<Post, 'title' | 'content' | 'user'>

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

const initialReactions: Reactions = {
  thumbsUp: 0,
  tada: 0,
  heart: 0,
  rocket: 0,
  eyes: 0,
}

interface PostsState {
  posts: Post[]
  status: 'idle' | 'pending' | 'succeeded' | 'rejected'
  error: string | null
}

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

const initialState: PostsState = {
  posts: [],
  status: 'idle',
  error: null,
}

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
      const existingPost = state.posts.find((post) => post.id === id)
      if (existingPost) {
        existingPost.title = title
        existingPost.content = content
      }
    },

    reactionAdded(state, action: PayloadAction<{ postId: string; reaction: ReactionName }>) {
      const { postId, reaction } = action.payload
      const existingPost = state.posts.find((post) => post.id === postId)
      if (existingPost) {
        existingPost.reactions[reaction]++
      }
    },
  },
  selectors: {
    // Note that these selectors are given just the `PostsState`
    // as an argument, not the entire `RootState`
    selectAllPosts: (postsState) => postsState.posts,
    selectPostById: (postsState, postId: string) => {
      return postsState.posts.find((post) => post.id === postId)
    },
    selectPostsStatus: (postState) => postState.status,
    selectPostsError: (postState) => postState.error,
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
      //
      .addCase(userLoggedOut, (state) => {
        // Clear out the list of posts whenever the user logs out
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
        // Add any fetched posts to the array
        state.posts.push(...action.payload)
      })
      .addCase(fetchPosts.rejected, (state, action) => {
        state.status = 'rejected'
        state.error = action.error.message ?? 'Unknown Error'
      })
      //
      // Add post from data fetched by API
      //
      .addCase(addNewPost.fulfilled, (state, action) => {
        // We can directly add the new post object to our posts array
        state.posts.push(action.payload)
      })
  },
})

// Export the auto-generated action creator with the same name
export const { /*postAdded,*/ postUpdated, reactionAdded } = postsSlice.actions

export default postsSlice.reducer

export const { selectAllPosts, selectPostById, selectPostsError, selectPostsStatus } = postsSlice.selectors
// export const selectAllPosts = (state: RootState) => state.posts
// export const selectPostById = (state: RootState, postId: string) => state.posts.find((post) => post.id === postId)
