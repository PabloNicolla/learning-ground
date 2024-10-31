import { createListenerMiddleware, addListener } from '@reduxjs/toolkit'
import type { RootState, AppDispatch } from './store'

import { addPostsListeners } from '@/features/posts/postsSlice'

export const listenerMiddleware = createListenerMiddleware()

export const startAppListening = listenerMiddleware.startListening.withTypes<RootState, AppDispatch>()
export type AppStartListening = typeof startAppListening

export const addAppListener = addListener.withTypes<RootState, AppDispatch>()
export type AppAddListener = typeof addAppListener

// Call this and pass in `startAppListening` to let the
// posts slice set up its listeners
addPostsListeners(startAppListening)

/*
We've already used the thunk middleware for async logic that has to run "right now". However, thunks are just functions. We need a different kind of middleware that lets us say "when a specific action is dispatched, go run this additional logic in response".

Redux Toolkit includes the createListenerMiddleware API to let us write logic that runs in response to specific actions being dispatched. It lets us add "listener" entries that define what actions to look for and have an effect callback that will run whenever it matches against an action.

Conceptually, you can think of createListenerMiddleware as being similar to React's useEffect hook, except that they are defined as part of your Redux logic instead of inside a React component, and they run in response to dispatched actions and Redux state updates instead of as part of React's rendering lifecycle.
*/
