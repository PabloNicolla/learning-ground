import { useAppDispatch, useAppSelector } from '@/app/hooks'
import { Post, postSelected } from './postsSlice'
import React from 'react'

export const PostsList = () => {
  const posts = useAppSelector((state) => state.posts.postsSaved)
  const renderedPosts = posts.map((post) => <PostComp post={post} key={post.id} />)
  return (
    <section className="posts-list">
      <h2>Posts</h2>
      {renderedPosts}
    </section>
  )
}

const PostComp = React.memo(({ post }: { post: Post }) => {
  const dispatch = useAppDispatch()
  const isSelected = useAppSelector((state) => !!state.posts.selectedPosts[post.id])

  console.log(post.id, 're-render')

  return (
    <article
      className="post-excerpt"
      key={post.id}
      style={{ backgroundColor: isSelected ? 'green' : 'blue' }}
      onClick={() => {
        console.log('Left click')
        dispatch(postSelected({ id: post.id, clickType: 'short' }))
      }}
      onContextMenu={(e) => {
        e.preventDefault() // This will prevent the default context menu
        console.log('Right click')
        dispatch(postSelected({ id: post.id, clickType: 'long' }))
      }}
    >
      <h3>{post.title}</h3>
      <p className="post-content">{post.content.substring(0, 100)}</p>
    </article>
  )
})
