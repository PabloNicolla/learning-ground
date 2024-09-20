import { useEffect, useMemo } from 'react'
import { Link } from 'react-router-dom'

import { useAppDispatch, useAppSelector } from '@/app/hooks'

import { Spinner } from '@/components/Spinner'
import { TimeAgo } from '@/components/TimeAgo'

import { PostAuthor } from './PostAuthor'
import { ReactionButtons } from './ReactionButtons'

import { fetchPosts, selectPostById, selectPostIds, selectPostsStatus, selectPostsError, Post } from './postsSlice'
import { useSelector } from 'react-redux'
import { useGetPostsQuery } from '../api/apiSlice'

import classnames from 'classnames'

// Go back to passing a `post` object as a prop
interface PostExcerptProps {
  post: Post
}

function PostExcerpt({ post }: PostExcerptProps) {
  return (
    <article className="post-excerpt" key={post.id}>
      <h3>
        <Link to={`/posts/${post.id}`}>{post.title}</Link>
      </h3>
      <div>
        <PostAuthor userId={post.user} />
        <TimeAgo timestamp={post.date} />
      </div>
      <p className="post-content">{post.content.substring(0, 100)}</p>
      <ReactionButtons post={post} />
    </article>
  )
}

/*
    data: the actual response contents from the server for the most recent successful cache entry data. This field will be undefined until the response is received.
    currentData: The response contents for the current query arguments. This can switch to undefined if the query arguments are changed and a request starts because there isn't an existing cache entry.
    isLoading: a boolean indicating if this hook is currently making the first request to the server because there isn't any data yet. (Note that if the parameters change to request different data, isLoading will remain false.)
    isFetching: a boolean indicating if the hook is currently making any request to the server
    isSuccess: a boolean indicating if the hook has made a successful request and has cached data available (ie, data should be defined now)
    isError: a boolean indicating if the last request had an error
    error: a serialized error object
*/

export const PostsList = () => {
  // Calling the `useGetPostsQuery()` hook automatically fetches data!
  const { data: posts = [], isLoading, isFetching, isSuccess, isError, error, refetch } = useGetPostsQuery()

  const sortedPosts = useMemo(() => {
    const sortedPosts = posts.slice()
    // Sort posts in descending chronological order
    sortedPosts.sort((a, b) => b.date.localeCompare(a.date))
    return sortedPosts
  }, [posts])

  let content: React.ReactNode

  // Show loading states based on the hook status flags
  if (isLoading) {
    content = <Spinner text="Loading..." />
  } else if (isSuccess) {
    const renderedPosts = sortedPosts.map((post) => <PostExcerpt key={post.id} post={post} />)

    const containerClassname = classnames('posts-container', {
      disabled: isFetching,
    })

    content = <div className={containerClassname}>{renderedPosts}</div>
  } else if (isError) {
    content = <div>{error.toString()}</div>
  }

  return (
    <section className="posts-list">
      <h2>Posts</h2>
      <button onClick={refetch}>Refetch Posts</button>
      {content}
    </section>
  )
}
