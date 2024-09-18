import { createSlice, PayloadAction } from '@reduxjs/toolkit'

import { client } from '@/api/client'

import type { RootState } from '@/app/store'

import { selectCurrentUsername } from '@/features/auth/authSlice'
import { createAppAsyncThunk } from '@/app/withTypes'

interface User {
  id: string
  name: string
}

export const fetchUsers = createAppAsyncThunk('users/fetchUsers', async () => {
  const response = await client.get<User[]>('/fakeApi/users')
  return response.data
})

const initialState: User[] = []

const usersSlice = createSlice({
  name: 'users',
  initialState,
  reducers: {},
  extraReducers(builder) {
    builder.addCase(fetchUsers.fulfilled, (state, action) => {
      // Immer lets us update state in two ways: either mutating the existing state value, or returning a new result
      // BUT NEVER DO BOTH
      return action.payload
    })
  },
})

export default usersSlice.reducer

export const selectAllUsers = (state: RootState) => state.users

export const selectUserById = (state: RootState, userId: string | null) =>
  state.users.find((user) => user.id === userId)

export const selectCurrentUser = (state: RootState) => {
  const currentUsername = selectCurrentUsername(state)
  return selectUserById(state, currentUsername)
}
