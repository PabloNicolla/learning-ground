import { client } from '@/api/client'
import { RootState } from '@/app/store'
import { createAppAsyncThunk } from '@/app/withTypes'
import { createSlice, PayloadAction } from '@reduxjs/toolkit'

interface AuthState {
  username: string | null
}

const initialState: AuthState = {
  // Note: a real app would probably have more complex auth state,
  // but for this example we'll keep things simple
  username: null,
}

export const login = createAppAsyncThunk('auth/login', async (username: string) => {
  await client.post('/fakeApi/login', { username })
  return username
})

export const logout = createAppAsyncThunk('auth/logout', async () => {
  await client.post('/fakeApi/logout', {})
})

const authSlice = createSlice({
  name: 'auth',
  initialState,
  reducers: {},
  extraReducers: (builder) => {
    // and handle the thunk actions instead
    builder
      .addCase(login.fulfilled, (state, action) => {
        state.username = action.payload
      })
      .addCase(logout.fulfilled, (state) => {
        state.username = null
      })
  },
})

export const selectCurrentUsername = (state: RootState) => state.auth.username

export default authSlice.reducer
