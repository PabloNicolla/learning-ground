import React from 'react'
import { createRoot } from 'react-dom/client'
import { Provider } from 'react-redux'

import App from './App'
import { store } from './app/store'

import { worker } from './api/server'

import './primitiveui.css'
import './index.css'
import { apiSliceWithUsers } from './features/users/usersSlice'

// Wrap app rendering so we can wait for the mock API to initialize
async function start() {
  // Start our mock API server
  await worker.start({ onUnhandledRequest: 'bypass' })

  /*
  Notice that this is a valid way to fetch data on startup.
  This actually starts the fetching process before we start rendering our React components,
  so the data should be available sooner.
  (Note that this principle can be applied by using React Router data loaders as well.)
  */
  // RTKQ request thunk will create a subscription entry, but it's then up to you to unsubscribe from that data later
  store.dispatch(apiSliceWithUsers.endpoints.getUsers.initiate())

  const root = createRoot(document.getElementById('root')!)

  root.render(
    <React.StrictMode>
      <Provider store={store}>
        <App />
      </Provider>
    </React.StrictMode>,
  )
}

start()
