import { useEffect } from 'react'
import { Link } from 'react-router-dom'

import { useAppDispatch, useAppSelector } from '@/app/hooks'

import { Spinner } from '@/components/Spinner'
import { TimeAgo } from '@/components/TimeAgo'

import { PostAuthor } from './PostAuthor'
import { ReactionButtons } from './ReactionButtons'

import { fetchPosts, selectPostById, selectPostIds, selectPostsStatus, selectPostsError } from './postsSlice'
import { useSelector } from 'react-redux'

interface PostExcerptProps {
  postId: string
}

function PostExcerpt({ postId }: PostExcerptProps) {
  const post = useAppSelector((state) => selectPostById(state, postId))

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
    // Use the shallowEqual function from React-Redux as the equalityFn argument to useSelector(), like:

import { shallowEqual, useSelector } from 'react-redux'

// Pass it as the second argument directly
const selectedData = useSelector(selectorReturningObject, shallowEqual)

// or pass it as the `equalityFn` field in the options argument
const selectedData = useSelector(selectorReturningObject, {
  equalityFn: shallowEqual,
})

    // Use a custom equality function as the equalityFn argument to useSelector(), like:

import { useSelector } from 'react-redux'

// equality function
const customEqual = (oldValue, newValue) => oldValue === newValue

// later
const selectedData = useSelector(selectorReturningObject, customEqual)
*/

export const PostsList = () => {
  // Select the `state.posts` value from the store into the component
  const dispatch = useAppDispatch()
  const orderedPostIds = useAppSelector(selectPostIds)
  const postStatus = useAppSelector(selectPostsStatus)
  const postsError = useAppSelector(selectPostsError)

  useEffect(() => {
    if (postStatus === 'idle') {
      dispatch(fetchPosts())
    }
  }, [postStatus, dispatch])

  let content: React.ReactNode

  if (postStatus === 'pending') {
    content = <Spinner text="Loading..." />
  } else if (postStatus === 'succeeded') {
    content = orderedPostIds.map((postId) => <PostExcerpt key={postId} postId={postId} />)
  } else if (postStatus === 'rejected') {
    content = <div>{postsError}</div>
  }

  return (
    <section className="posts-list">
      <h2>Posts</h2>
      {content}
    </section>
  )
}
