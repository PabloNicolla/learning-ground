// Import the RTK Query methods from the React-specific entry point
import { createApi, fetchBaseQuery } from '@reduxjs/toolkit/query/react'

// Use the `Post` type we've already defined in `postsSlice`,
// and then re-export it for ease of use
import type { Post, NewPost, PostUpdate, ReactionName } from '@/features/posts/postsSlice'
import type { User } from '@/features/users/usersSlice'
export type { Post }

/*
Basic tag usage requires adding three pieces of information to our API slice:

    A root tagTypes field in the API slice object, declaring an array of string tag names for data types such as 'Post'
    A providesTags array in query endpoints, listing a set of tags describing the data in that query
    An invalidatesTags array in mutation endpoints, listing a set of tags that are invalidated every time that mutation runs
*/

// https://redux-toolkit.js.org/rtk-query/usage/automated-refetching#tag-invalidation-behavior

// Define our single API slice object
export const apiSlice = createApi({
  // The cache reducer expects to be added at `state.api` (already default - this is optional)
  reducerPath: 'api',
  // All of our requests will have URLs starting with '/fakeApi'
  baseQuery: fetchBaseQuery({ baseUrl: '/fakeApi' }),
  // Tag for smart cache management
  tagTypes: ['Post'],
  // The "endpoints" represent operations and requests for this server
  endpoints: (builder) => ({
    // The `getPosts` endpoint is a "query" operation that returns data.
    // The return value is a `Post[]` array, and it takes no arguments.
    // <ReturnType, ArgumentType>
    getPosts: builder.query<Post[], void>({
      // The URL for the request is '/fakeApi/posts'
      // override by returning an object like {url: '/posts', method: 'POST', body: newPost}
      query: () => '/posts',
      // providesTags: ['Post'],
      providesTags: (result = [], error, arg) => ['Post', ...result.map(({ id }) => ({ type: 'Post', id }) as const)],
    }),
    getPost: builder.query<Post, string>({
      query: (postId) => `/posts/${postId}`,
      providesTags: (result, error, arg) => [{ type: 'Post', id: arg }],
      // keepUnusedDataFor: 300,  // Cache data for 5 minutes
    }),
    addNewPost: builder.mutation<Post, NewPost>({
      query: (initialPost) => ({
        // The HTTP URL will be '/fakeApi/posts'
        url: '/posts',
        // This is an HTTP POST request, sending an update
        method: 'POST',
        // Include the entire post object as the body of the request
        body: initialPost,
      }),
      invalidatesTags: ['Post'],
    }),
    editPost: builder.mutation<Post, PostUpdate>({
      query: (post) => ({
        url: `posts/${post.id}`,
        method: 'PATCH',
        body: post,
      }),
      invalidatesTags: (result, error, arg) => [{ type: 'Post', id: arg.id }],
    }),

    // Moved to another file
    // getUsers: builder.query<User[], void>({
    //   query: () => '/users',
    // }),

    addReaction: builder.mutation<Post, { postId: string; reaction: ReactionName }>({
      query: ({ postId, reaction }) => ({
        url: `posts/${postId}/reactions`,
        method: 'POST',
        // In a real app, we'd probably need to base this on user ID somehow
        // so that a user can't do the same reaction more than once
        body: { reaction },
      }),
      // invalidatesTags: (result, error, arg) => [{ type: 'Post', id: arg.postId }],
      // The `invalidatesTags` line has been removed,
      // since we're now doing optimistic updates
      async onQueryStarted({ postId, reaction }, lifecycleApi) {
        // `updateQueryData` requires the endpoint name and cache key arguments,
        // so it knows which piece of cache state to update
        const getPostsPatchResult = lifecycleApi.dispatch(
          apiSlice.util.updateQueryData('getPosts', undefined, (draft) => {
            // The `draft` is Immer-wrapped and can be "mutated" like in createSlice
            const post = draft.find((post) => post.id === postId)
            if (post) {
              post.reactions[reaction]++
            }
          }),
        )

        // We also have another copy of the same data in the `getPost` cache
        // entry for this post ID, so we need to update that as well
        const getPostPatchResult = lifecycleApi.dispatch(
          apiSlice.util.updateQueryData('getPost', postId, (draft) => {
            draft.reactions[reaction]++
          }),
        )

        try {
          await lifecycleApi.queryFulfilled
          /*
          Sometimes mutation requests come back with meaningful data in the server response, 
          such as a final item ID that should replace a temporary client-side ID, or other related data. 
          If we did the const res = await lifecycleApi.queryFulfilled first, 
          we could then use the data from the response after that to apply cache updates as a "pessimistic" update.
          */
        } catch {
          getPostsPatchResult.undo()
          getPostPatchResult.undo()
        }
      },
    }),
  }),
})

// Export the auto-generated hook for the `getPosts` query endpoint
export const { useGetPostsQuery, useGetPostQuery, useAddNewPostMutation, useEditPostMutation, useAddReactionMutation } =
  apiSlice
