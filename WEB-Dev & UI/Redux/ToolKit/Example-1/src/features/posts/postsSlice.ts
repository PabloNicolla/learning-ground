import { createSlice, PayloadAction } from '@reduxjs/toolkit'

export interface Post {
  id: string
  title: string
  content: string
}

const initialState: {
  postsSaved: Post[]
  selectedPosts: Record<Post['id'], boolean>
  isSelectionActive: boolean
  selectedCount: number
} = {
  postsSaved: [
    { id: '1', title: 'First Post!', content: 'Hello!' },
    { id: '2', title: 'Second Post', content: 'More text' },
  ],
  selectedPosts: {},
  isSelectionActive: false,
  selectedCount: 0,
}

interface postSelectedActionType {
  id: Post['id']
  clickType: 'short' | 'long'
}

const postsSlice = createSlice({
  name: 'posts',
  initialState,
  reducers: {
    postAdded(state, action: PayloadAction<Post>) {
      state.postsSaved.push(action.payload)
    },
    postSelected(state, action: PayloadAction<postSelectedActionType>) {
      const postId = action.payload.id
      if (action.payload.clickType === 'long') {
        state.isSelectionActive = true
      }
      if (state.isSelectionActive) {
        if (state.selectedPosts[postId]) {
          delete state.selectedPosts[postId] // Deselect post
          state.selectedCount--
          if (state.selectedCount === 0) {
            state.isSelectionActive = false
          }
        } else {
          state.selectedPosts[postId] = true // Select post
          state.selectedCount++
        }
      }
    },
  },
})

export const { postAdded, postSelected } = postsSlice.actions
export default postsSlice.reducer
