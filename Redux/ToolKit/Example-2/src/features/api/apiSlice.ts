// Import the RTK Query methods from the React-specific entry point
import { createApi, fetchBaseQuery } from '@reduxjs/toolkit/query/react'

// Use the `Post` type we've already defined in `postsSlice`,
// and then re-export it for ease of use
import type { Post, NewPost } from '@/features/posts/postsSlice'
export type { Post }

/*
Basic tag usage requires adding three pieces of information to our API slice:

    A root tagTypes field in the API slice object, declaring an array of string tag names for data types such as 'Post'
    A providesTags array in query endpoints, listing a set of tags describing the data in that query
    An invalidatesTags array in mutation endpoints, listing a set of tags that are invalidated every time that mutation runs
*/

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
      providesTags: ['Post'],
    }),
    getPost: builder.query<Post, string>({
      query: (postId) => `/posts/${postId}`,
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
  }),
})

// Export the auto-generated hook for the `getPosts` query endpoint
export const { useGetPostsQuery, useGetPostQuery, useAddNewPostMutation } = apiSlice
