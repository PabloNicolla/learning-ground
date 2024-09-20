import { Action, configureStore, ThunkAction } from '@reduxjs/toolkit'

// Removed the `counterReducer` function, `CounterState` type, and `Action` import

import postsReducer from '@/features/posts/postsSlice'
import authReducer from '@/features/auth/authSlice'
import notificationReducer from '@/features/notifications/notificationsSlice'
import { listenerMiddleware } from './listenerMiddleware'
import { apiSlice } from '@/features/api/apiSlice'

export const store = configureStore({
  reducer: {
    posts: postsReducer,
    auth: authReducer,
    notifications: notificationReducer,
    [apiSlice.reducerPath]: apiSlice.reducer,
  },
  // .concat()  add to array's end
  // .prepend() add to array's start
  // middleware order matters m1 -> m2 -> m3 -> store.dispatch()
  middleware: (getDefaultMiddleware) =>
    getDefaultMiddleware().prepend(listenerMiddleware.middleware).concat(apiSlice.middleware),
})

// Infer the type of `store`
export type AppStore = typeof store
// Infer the `AppDispatch` type from the store itself
export type AppDispatch = typeof store.dispatch
// Same for the `RootState` type
export type RootState = ReturnType<typeof store.getState>
// Export a reusable type for handwritten thunks
export type AppThunk = ThunkAction<void, RootState, unknown, Action>

/*
// Example typed thunk
// (this code would be on a slice file)
//
// // Use `AppThunk` as the return type, since we return a thunk function
  const logAndAdd = (amount: number): AppThunk => {
    return (dispatch, getState) => {
      const stateBefore = getState()
      console.log(`Counter before: ${stateBefore.counter}`)
      dispatch(incrementByAmount(amount))
      const stateAfter = getState()
      console.log(`Counter after: ${stateAfter.counter}`)
    }
  }

  store.dispatch(logAndAdd(5))
*/

/*
const getRepoDetailsStarted = () => ({
  type: 'repoDetails/fetchStarted'
})
const getRepoDetailsSuccess = (repoDetails: RepoDetails) => ({
  type: 'repoDetails/fetchSucceeded',
  payload: repoDetails
})
const getRepoDetailsFailed = (error: any) => ({
  type: 'repoDetails/fetchFailed',
  error
})

const fetchIssuesCount = (org: string, repo: string) => {
  return async (dispatch: AppDispatch) => {
    dispatch(getRepoDetailsStarted())
    try {
      const repoDetails = await getRepoDetails(org, repo)
      dispatch(getRepoDetailsSuccess(repoDetails))
    } catch (err) {
      dispatch(getRepoDetailsFailed(err.toString()))
    }
  }
}
*/
