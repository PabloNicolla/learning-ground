import { createEntityAdapter, createSelector, EntityState } from '@reduxjs/toolkit'

import type { RootState } from '@/app/store'

import { selectCurrentUsername } from '@/features/auth/authSlice'
import { apiSlice } from '../api/apiSlice'

export interface User {
  id: string
  name: string
}

const usersAdapter = createEntityAdapter<User>()
const initialState = usersAdapter.getInitialState()

// This is the _same_ reference as `apiSlice`, but this has
// the TS types updated to include the injected endpoints
export const apiSliceWithUsers = apiSlice.injectEndpoints({
  endpoints: (builder) => ({
    getUsers: builder.query<EntityState<User, string>, void>({
      query: () => '/users',
      transformResponse(res: User[]) {
        // Create a normalized state object containing all the user items
        return usersAdapter.setAll(initialState, res)
      },
    }),
  }),
})

export const { useGetUsersQuery } = apiSliceWithUsers

const emptyUsers: User[] = []

// Calling `someEndpoint.select(someArg)` generates a new selector that will return
// the query result object for a query with those parameters.
// To generate a selector for a specific query argument, call `select(theQueryArg)`.
// In this case, the users query has no params, so we don't pass anything to select()

// export const selectUsersResult = apiSlice.endpoints.getUsers.select()

export const selectUsersResult = apiSliceWithUsers.endpoints.getUsers.select()

const selectUsersData = createSelector(
  selectUsersResult,
  // Fall back to the empty entity state if no response yet.
  (result) => result.data ?? initialState,
)

export const selectCurrentUser = (state: RootState) => {
  const currentUsername = selectCurrentUsername(state)
  if (currentUsername) {
    return selectUserById(state, currentUsername)
  }
}

export const { selectAll: selectAllUsers, selectById: selectUserById } = usersAdapter.getSelectors(selectUsersData)
