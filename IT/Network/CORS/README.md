# Cross-Origin Resource Sharing (CORS)

- [Cross-Origin Resource Sharing (CORS)](#cross-origin-resource-sharing-cors)
  - [Introduction](#introduction)
  - [How CORS Works](#how-cors-works)
  - [CORS Example](#cors-example)

## Introduction

Cross-Origin Resource Sharing (CORS) is a security feature implemented in web browsers that allows or restricts web pages from making requests to a domain different from the one that served the web page. This is essential because, by default, web browsers enforce the Same-Origin Policy (SOP), which prevents scripts on a web page from making requests to a different domain, protocol, or port than the one that originated the content.

## How CORS Works

When a web page makes an HTTP request to a different domain (cross-origin), the browser sends a preflight request (using the HTTP OPTIONS method) to the server to check if the cross-origin request is allowed. The server can respond with specific headers to either grant or deny the request. If the request is allowed, the browser proceeds with the actual request; otherwise, it blocks the request.
CORS Headers:

- Access-Control-Allow-Origin: Specifies which origin is allowed to access the resource. It can be a specific domain (e.g., `https://example.com`) or a wildcard (*) to allow any origin.
- Access-Control-Allow-Methods: Lists the HTTP methods (e.g., GET, POST, DELETE, etc.) that are allowed for cross-origin requests.
- Access-Control-Allow-Headers: Specifies which HTTP headers can be used in the actual request.
- Access-Control-Allow-Credentials: Indicates whether the browser should include credentials (like cookies or HTTP authentication) with the request.
- Access-Control-Expose-Headers: Lists the headers that are safe to expose to the client.

## CORS Example

Suppose you have a frontend application hosted at `https://frontend.example.com` that needs to interact with an API hosted at `https://api.example.com`. By default, the browser would block requests from the frontend to the API due to the Same-Origin Policy. To enable communication, you would configure CORS on the API server.

Server-Side Configuration:

Here’s an example of a CORS policy in an Express.js (Node.js) API:

```javascript
const express = require('express');
const app = express();

// Enable CORS for requests from https://frontend.example.com
app.use((req, res, next) => {
  res.header('Access-Control-Allow-Origin', 'https://frontend.example.com');
  res.header('Access-Control-Allow-Methods', 'GET, POST, PUT, DELETE');
  res.header('Access-Control-Allow-Headers', 'Content-Type, Authorization');
  res.header('Access-Control-Allow-Credentials', 'true');
  next();
});

app.get('/data', (req, res) => {
  res.json({ message: 'This is CORS-enabled for a specific origin!' });
});

app.listen(3000, () => {
  console.log('API server is running on port 3000');
});
```

**Explanation:**

- Access-Control-Allow-Origin: Only allows requests from `https://frontend.example.com`. If you wanted to allow any origin, you could use *.
- Access-Control-Allow-Methods: Specifies the allowed HTTP methods for cross-origin requests.
- Access-Control-Allow-Headers: Lists the headers that are allowed in requests.
- Access-Control-Allow-Credentials: Indicates that cookies or HTTP authentication information should be sent with the request.

**How it Works in Practice:**

- Preflight Request: When `https://frontend.example.com` tries to access `https://api.example.com/data`, the browser sends an OPTIONS request to check if the domain is allowed.
- Server Response: The API server responds with the CORS headers, indicating whether the request is allowed.
- Actual Request: If the response headers indicate that the request is permitted, the browser proceeds with the actual request (e.g., GET /data). If not, the request is blocked.

This CORS setup ensures that only the specified frontend can interact with the API, preventing unauthorized domains from accessing it.
