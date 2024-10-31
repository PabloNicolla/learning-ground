import { Link, useParams } from 'react-router-dom'
import { createSelector } from '@reduxjs/toolkit'
import type { TypedUseQueryStateResult } from '@reduxjs/toolkit/query/react'

import { useAppSelector } from '@/app/hooks'

import { useGetPostsQuery, Post } from '@/features/api/apiSlice'

import { selectUserById } from './usersSlice'

// Create a TS type that represents "the result value passed
// into the `selectFromResult` function for this hook"
type GetPostSelectFromResultArg = TypedUseQueryStateResult<Post[], any, any>

const selectPostsForUser = createSelector(
  (res: GetPostSelectFromResultArg) => res.data,
  (res: GetPostSelectFromResultArg, userId: string) => userId,
  (data, userId) => data?.filter((post) => post.user === userId),
)

/*
Comparing Transformation Approaches

We've now seen three different ways that we can manage transforming responses:

    Keep original response in cache, read full result in component and derive values
    Keep original response in cache, read derived result with selectFromResult
    Transform response before storing in cache

Each of these approaches can be useful in different situations. Here's some suggestions for when you should consider using them:

    transformResponse: all consumers of the endpoint want a specific format, such as normalizing the response to enable faster lookups by ID
    selectFromResult: some consumers of the endpoint only need partial data, such as a filtered list
    per-component / useMemo: when only some specific components need to transform the cached data
*/

export const UserPage = () => {
  const { userId } = useParams()

  const user = useAppSelector((state) => selectUserById(state, userId!))

  // Use the same posts query, but extract only part of its data
  const { postsForUser } = useGetPostsQuery(undefined, {
    selectFromResult: (result) => ({
      // Optional: Include all of the existing result fields like `isFetching`
      ...result,
      // Include a field called `postsForUser` in the result object,
      // which will be a filtered list of posts
      postsForUser: selectPostsForUser(result, userId!),
    }),
  })

  const postTitles = postsForUser?.map((post) => (
    <li key={post.id}>
      <Link to={`/posts/${post.id}`}>{post.title}</Link>
    </li>
  ))

  return (
    <section>
      <h2>{user.name}</h2>

      <ul>{postTitles}</ul>
    </section>
  )
}
