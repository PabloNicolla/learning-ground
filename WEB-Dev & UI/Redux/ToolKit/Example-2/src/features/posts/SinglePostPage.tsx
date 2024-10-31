import { Link, useParams } from 'react-router-dom'

import { useAppSelector } from '@/app/hooks'
import { selectPostById } from './postsSlice'
import { PostAuthor } from './PostAuthor'
import { TimeAgo } from '@/components/TimeAgo'
import { ReactionButtons } from './ReactionButtons'

import { selectCurrentUsername } from '@/features/auth/authSlice'
import { useGetPostQuery } from '../api/apiSlice'
import { Spinner } from '@/components/Spinner'

/*
RTK Query creates a "cache key" for each unique endpoint + argument combination, and stores the results for each cache key separately. That means that you can use the same query hook multiple times, pass it different query parameters, and each result will be cached separately in the Redux store.
*/

export const SinglePostPage = () => {
  const { postId } = useParams()

  const currentUsername = useAppSelector(selectCurrentUsername)!
  const { data: post, isFetching, isSuccess } = useGetPostQuery(postId!)

  // if (!post) {
  //   return (
  //     <section>
  //       <h2>Post not found!</h2>
  //     </section>
  //   )
  // }

  let content: React.ReactNode

  const canEdit = currentUsername === post?.user

  if (isFetching) {
    content = <Spinner text="Loading..." />
  } else if (isSuccess) {
    content = (
      <article className="post">
        <h2>{post.title}</h2>
        <div>
          <PostAuthor userId={post.user} />
          <TimeAgo timestamp={post.date} />
        </div>
        <p className="post-content">{post.content}</p>
        <ReactionButtons post={post} />
        {canEdit && (
          <Link to={`/editPost/${post.id}`} className="button">
            Edit Post
          </Link>
        )}
      </article>
    )
  }

  return <section>{content}</section>
}
