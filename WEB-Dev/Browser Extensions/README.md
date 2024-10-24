# Browser Extensions

- [Browser Extensions](#browser-extensions)
  - [Overview (Firefox and Chromium)](#overview-firefox-and-chromium)
  - [WebExtensions API (Unified for Chromium and Firefox)](#webextensions-api-unified-for-chromium-and-firefox)
    - [Key Concepts in Browser Extensions](#key-concepts-in-browser-extensions)
    - [Main Components of an Extension](#main-components-of-an-extension)
      - [Background Scripts](#background-scripts)
      - [Content Scripts](#content-scripts)
      - [Popup Scripts](#popup-scripts)
      - [Options Page](#options-page)
    - [Permissions](#permissions)
    - [Communication Between Components](#communication-between-components)
    - [Development Tools](#development-tools)
    - [Storage Options](#storage-options)
  - [Firefox-Specific Considerations](#firefox-specific-considerations)
  - [Testing and Debugging](#testing-and-debugging)
  - [Publishing and Distribution](#publishing-and-distribution)
  - [Conclusion](#conclusion)

## Overview (Firefox and Chromium)

Browser extensions are small software programs that modify and enhance the functionality of a browser. They can range from simple UI tweaks to complex background processes that interact with a variety of web APIs. Both Firefox and Chromium (which powers Chrome, Edge, and other browsers) support extensions, but their APIs have some differences. Here's a detailed breakdown focusing on the development side.

## WebExtensions API (Unified for Chromium and Firefox)

Both Firefox and Chromium (Chrome, Edge, Opera, Brave) support the WebExtensions API, which is a standardized API for creating browser extensions. The goal of the WebExtensions API is to provide a common platform for developers, allowing extensions to work across different browsers with minimal changes.

### Key Concepts in Browser Extensions

- Manifest File (manifest.json):
  - The manifest.json file is the blueprint of the extension. It defines essential information like permissions, background scripts, content scripts, browser actions, and UI elements like the toolbar icon.
  - Manifest V2 vs V3:
    - Chromium browsers are transitioning from Manifest V2 to Manifest V3, which changes how background scripts and permissions are handled (more focus on service workers for background tasks).
    - Firefox has maintained support for both, but is also adopting Manifest V3.

```json
{
  "manifest_version": 3,
  "name": "My Extension",
  "version": "1.0",
  "permissions": ["tabs", "storage"],
  "background": {
    "service_worker": "background.js"
  },
  "action": {
    "default_popup": "popup.html",
    "default_icon": "icon.png"
  },
  "content_scripts": [
    {
      "matches": ["https://*.example.com/*"],
      "js": ["content.js"]
    }
  ]
}
```

### Main Components of an Extension

#### Background Scripts

- Purpose: Run in the background to listen for browser events (e.g., tab updates, network requests) and execute logic without affecting the webpage.
- Chromium: Uses Service Workers in Manifest V3 for background tasks instead of long-running background pages.
- Firefox: Supports both persistent background pages (Manifest V2) and service workers (Manifest V3).
- Common Tasks: Handle events such as browser startup, network requests, alarms, or storage changes.

```js
// background.js (Manifest V3 - Service Worker)
chrome.runtime.onInstalled.addListener(() => {
  console.log('Extension installed');
});
```

#### Content Scripts

- Purpose: Inject JavaScript and CSS into web pages. Content scripts interact with the DOM of the page but are sandboxes from the rest of the page's scripts.
- Access: These scripts cannot access certain browser APIs directly (e.g., chrome.tabs), but they can communicate with background scripts using message passing.

```js
// content.js
document.body.style.backgroundColor = 'lightblue';
```

#### Popup Scripts

- These handle logic for a small UI panel (popup) when the extension icon is clicked. The popup is defined by default_popup in the manifest.json.
- Commonly used for user interaction and configuration settings.

```html
<!-- popup.html -->
<button id="changeColor">Change Background Color</button>

<script src="popup.js"></script>
```

```js
// popup.js
document.getElementById('changeColor').addEventListener('click', () => {
  chrome.tabs.query({ active: true, currentWindow: true }, (tabs) => {
    chrome.scripting.executeScript({
      target: { tabId: tabs[0].id },
      function: changeColor
    });
  });
});

function changeColor() {
  document.body.style.backgroundColor = 'yellow';
}
```

#### Options Page

- An HTML page where users can configure settings for the extension. The options page can be defined in the manifest.json and use the browser's storage APIs to persist settings.

```json
{
  "options_page": "options.html"
}
```

```html
<!-- options.html -->
<input type="color" id="bgColor" />
<button id="saveBtn">Save</button>

<script src="options.js"></script>
```

```js
// options.js
document.getElementById('saveBtn').addEventListener('click', () => {
  let bgColor = document.getElementById('bgColor').value;
  chrome.storage.sync.set({ backgroundColor: bgColor }, () => {
    console.log('Color saved');
  });
});
```

### Permissions

Extensions need explicit permissions to access browser features like tabs, bookmarks, storage, and web requests. These are declared in the manifest.json.

- Common Permissions:
  - tabs: Access to browser tabs and window manipulation.
  - storage: Access to browser storage (sync and local).
  - scripting: Required to run scripts in the context of a tab (new in Manifest V3).
  - webRequest: Intercept and modify network requests.
  - cookies: Access to cookies for specific domains.

### Communication Between Components

- Message Passing:
  - Background scripts, content scripts, popups, and other parts of an extension need to communicate via message passing, either one-time messages or persistent connections using runtime.connect.

```js

// content.js
chrome.runtime.sendMessage({ greeting: 'hello' }, (response) => {
  console.log(response.farewell);
});

// background.js
chrome.runtime.onMessage.addListener((request, sender, sendResponse) => {
  if (request.greeting === 'hello') {
    sendResponse({ farewell: 'goodbye' });
  }
});
```

### Development Tools

- Chrome/Firefox DevTools:
  - Both browsers provide developer tools specifically for extensions. You can inspect background pages, debug content scripts, and view the extension’s logs in the DevTools console.
- Local Development:
  - Extensions can be loaded locally without publishing to a store using developer mode. In Chrome, this is done through chrome://extensions and in Firefox through about:debugging.

### Storage Options

- chrome.storage API:
  - The storage API allows extensions to persist data. It supports two types of storage: local (stored on the user's machine) and sync (synchronized across user devices via the cloud).

```js
// Saving data
chrome.storage.sync.set({ key: 'value' }, () => {
  console.log('Data saved');
});

// Retrieving data
chrome.storage.sync.get(['key'], (result) => {
  console.log('Value is ' + result.key);
});
```

## Firefox-Specific Considerations

- Manifest Compatibility: Firefox is generally compatible with Chromium’s WebExtensions API, but with some differences:
  - Firefox still supports some deprecated APIs (like browserAction instead of action).
  - The browser namespace in Firefox is a promise-based version of chrome (e.g., browser.tabs.query() returns a promise, while chrome.tabs.query() uses a callback).

```js
// Firefox uses promises
browser.tabs.query({ active: true, currentWindow: true }).then((tabs) => {
  console.log(tabs);
});
```

- Native Messaging: Firefox allows extensions to communicate with native applications via native messaging. This requires a native host application installed on the user's machine.

## Testing and Debugging

- Unit Tests: You can use JavaScript testing frameworks like Jest or Mocha to test non-browser-specific functionality in your extension.

- Integration Testing: Tools like Selenium or Puppeteer can automate browser interactions to test how your extension behaves in the real world.

## Publishing and Distribution

- Chromium: Extensions are published through the Chrome Web Store. Each extension is reviewed, and certain permissions (e.g., accessing cookies or web requests) require justification.
- Firefox: Extensions are published on addons.mozilla.org (AMO). Firefox also has a review process, and developers can provide self-hosted extensions outside of AMO.

## Conclusion

Browser extensions provide a powerful way to extend browser functionality. While Firefox and Chromium share the WebExtensions API, there are still differences in how certain features like background scripts or permissions are handled. As an extension developer, understanding the nuances of the WebExtensions API, the manifest file, permissions, and communication patterns is key to creating effective and cross-browser extensions.
