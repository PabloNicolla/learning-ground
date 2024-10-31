import React, { useState } from 'react'
import { nanoid } from '@reduxjs/toolkit'
import { useAppDispatch, useAppSelector } from '@/app/hooks'
import { addNewPost, Post } from './postsSlice'

import { selectAllUsers } from '@/features/users/usersSlice'
import { selectCurrentUsername } from '../auth/authSlice'

// TS types for the input fields
// See: https://epicreact.dev/how-to-type-a-react-form-on-submit-handler/
interface AddPostFormFields extends HTMLFormControlsCollection {
  postTitle: HTMLInputElement
  postContent: HTMLTextAreaElement
  postAuthor: HTMLSelectElement
}
interface AddPostFormElements extends HTMLFormElement {
  readonly elements: AddPostFormFields
}

export const AddPostForm = () => {
  const [addRequestStatus, setAddRequestStatus] = useState<'idle' | 'pending'>('idle')

  const dispatch = useAppDispatch()
  const userId = useAppSelector(selectCurrentUsername)!

  const handleSubmit = async (e: React.FormEvent<AddPostFormElements>) => {
    // Prevent server submission
    e.preventDefault()

    const { elements } = e.currentTarget
    const title = elements.postTitle.value
    const content = elements.postContent.value
    // Removed the `postAuthor` field everywhere in the component

    const form = e.currentTarget

    try {
      setAddRequestStatus('pending')
      /*
      createAsyncThunk handles any errors internally, so that we don't see any messages about "rejected Promises" in our logs. It then returns the final action it dispatched: either the fulfilled action if it succeeded, or the rejected action if it failed. That means that await dispatch(someAsyncThunk()) always "succeeds", and the result is the action object itself.

      However, it's common to want to write logic that looks at the success or failure of the actual request that was made. Redux Toolkit adds a .unwrap() function to the returned Promise, which will return a new Promise that either has the actual action.payload value from a fulfilled action, or throws an error if it's the rejected action. This lets us handle success and failure in the component using normal try/catch logic. So, we'll clear out the input fields to reset the form if the post was successfully created, and log the error to the console if it failed.
      */
      await dispatch(addNewPost({ title, content, user: userId })).unwrap()

      form.reset()
    } catch (err) {
      console.error('Failed to save the post: ', err)
    } finally {
      setAddRequestStatus('idle')
    }
  }

  return (
    <section>
      <h2>Add a New Post</h2>
      <form onSubmit={handleSubmit}>
        <label htmlFor="postTitle">Post Title:</label>
        <input type="text" id="postTitle" defaultValue="" required />
        <label htmlFor="postContent">Content:</label>
        <textarea id="postContent" name="postContent" defaultValue="" required />
        <button disabled={addRequestStatus === 'pending'}>Save Post</button>
      </form>
    </section>
  )
}
