# CDN and Local cache

- [CDN and Local cache](#cdn-and-local-cache)
  - [Introduction](#introduction)
  - [1. **Using CDN to Cache Specific Static Pages While Not Caching Dynamic Pages**](#1-using-cdn-to-cache-specific-static-pages-while-not-caching-dynamic-pages)
    - [Overview](#overview)
    - [**How It Works:**](#how-it-works)
    - [**Configuration Steps:**](#configuration-steps)
    - [**Pros and Cons:**](#pros-and-cons)
    - [**Example:**](#example)
  - [2. **Static Site Generation (SSG) x CDN**](#2-static-site-generation-ssg-x-cdn)
    - [Overview](#overview-1)
    - [**How It Works:**](#how-it-works-1)
    - [**Configuration Steps:**](#configuration-steps-1)
    - [**Pros and Cons:**](#pros-and-cons-1)
    - [**Example with Next.js**](#example-with-nextjs)
  - [3. **Cache the Page on the User's Computer/Browser x CDN**](#3-cache-the-page-on-the-users-computerbrowser-x-cdn)
    - [Overview](#overview-2)
    - [**How It Works:**](#how-it-works-2)
    - [**Configuration Steps:**](#configuration-steps-2)
    - [**Pros and Cons:**](#pros-and-cons-2)
    - [**Browser Cache x CDN Flow:**](#browser-cache-x-cdn-flow)
    - [**Best Practices**](#best-practices)
  - [**Conclusion**](#conclusion)

## Introduction

Caching pages of a web application is a critical aspect of optimizing performance and reducing server load. Let's dive into each approach in detail:

## 1. **Using CDN to Cache Specific Static Pages While Not Caching Dynamic Pages**

### Overview

Content Delivery Networks (CDNs) are a network of distributed servers that deliver content based on the geographic location of the user. CDNs are highly effective for caching **static assets** (e.g., HTML, CSS, JS, images) to improve load times and reduce the load on your origin server.

### **How It Works:**

- **Static Pages** (e.g., marketing pages, documentation): These are typically cached by the CDN since they do not change often.
- **Dynamic Pages** (e.g., user dashboards, personalized content): These are **not cached** by default to ensure users receive the most recent data.

### **Configuration Steps:**

1. **Define Cache Rules**:
   - Configure cache rules at the CDN level to cache only specific pages or routes. For example, in Cloudflare or AWS CloudFront, you can set cache behaviors using URL patterns:
     - Cache `/about`, `/docs`, `/pricing`.
     - Do not cache `/profile`, `/dashboard`, `/api/*`.

2. **Cache-Control Headers**:
   - Use `Cache-Control` headers to define how your content should be cached.
     - For static pages:

       ```text
       Cache-Control: public, max-age=86400
       ```

       - This tells the CDN and browsers to cache the page for 1 day.
     - For dynamic pages:

       ```text
       Cache-Control: no-store, no-cache, must-revalidate
       ```

       - This ensures dynamic content is fetched from the origin server every time.

3. **Use Edge Side Includes (ESI)** (Optional):
   - If you need a mix of static and dynamic content, ESI allows dynamic fragments to be fetched separately while the main static content is cached.

### **Pros and Cons:**

| Pros                                    | Cons                                                                     |
| --------------------------------------- | ------------------------------------------------------------------------ |
| Reduces server load and latency         | Requires careful configuration to avoid caching dynamic data             |
| Improves scalability and response times | Can lead to stale content if cache invalidation is not handled correctly |

### **Example:**

Using Cloudflare Workers to control cache:

```javascript
addEventListener('fetch', event => {
  event.respondWith(handleRequest(event.request))
})

async function handleRequest(request) {
  const cacheURL = new URL(request.url)

  // If the URL matches a static page, enable caching
  if (cacheURL.pathname.startsWith('/static/')) {
    return fetch(request, { cf: { cacheEverything: true } })
  }
  
  // For dynamic content, bypass the cache
  return fetch(request, { cf: { cacheEverything: false } })
}
```

## 2. **Static Site Generation (SSG) x CDN**

### Overview

**Static Site Generation (SSG)** is a method where HTML pages are pre-rendered at build time and served as static files. This approach is highly effective when combined with a CDN, as the static files can be distributed globally for fast delivery.

### **How It Works:**

- During the build process, all static pages are generated based on content and templates.
- The generated HTML files are deployed to a CDN (e.g., Vercel, Netlify, AWS CloudFront).
- The CDN caches these static files and serves them to users, ensuring low latency.

### **Configuration Steps:**

1. **Generate Static Files**:
   - In frameworks like Next.js, use `getStaticProps` to generate static pages at build time.
   - In Gatsby, content is pre-rendered during the build process.

2. **Deploy to CDN**:
   - Use platforms like Vercel or Netlify that have built-in CDNs.
   - For custom setups, deploy the static files to a CDN like AWS S3 + CloudFront or Azure CDN.

3. **Configure Cache-Control Headers**:
   - Set `Cache-Control: public, max-age=86400, immutable` for pages that rarely change.
   - For pages that may change frequently, consider using `stale-while-revalidate`:

     ```text
     Cache-Control: public, max-age=3600, stale-while-revalidate=86400
     ```

### **Pros and Cons:**

| Pros                                  | Cons                                             |
| ------------------------------------- | ------------------------------------------------ |
| Very fast load times                  | Content is static; requires rebuilds for updates |
| Ideal for SEO and predictable content | Not suitable for highly dynamic pages            |
| Easy to scale with CDNs               | Build times can be long for large sites          |

### **Example with Next.js**

```javascript
export async function getStaticProps() {
  const data = await fetchData();
  return {
    props: {
      data,
    },
  };
}
```

- The above code fetches data at build time and generates static pages, which are then cached by the CDN.

## 3. **Cache the Page on the User's Computer/Browser x CDN**

### Overview

Caching on the user's browser leverages **browser cache** to store assets or pages locally, reducing the need to fetch them from the server or CDN repeatedly. This can significantly improve the perceived load time for returning users.

### **How It Works:**

- When a user visits a web page, the browser checks if the requested resources (HTML, CSS, JS, images) are already stored locally in the cache.
- If a cached version exists and is valid (not expired), the browser serves it directly.
- If not, it fetches the resource from the CDN, which may also have a cached version.

### **Configuration Steps:**

1. **Set Cache-Control Headers**:
   - For assets that do not change frequently (e.g., logo, fonts):

     ```text
     Cache-Control: public, max-age=31536000, immutable
     ```

   - For pages that may be updated, use `stale-while-revalidate`:

     ```text
     Cache-Control: public, max-age=300, stale-while-revalidate=86400
     ```

2. **Use Service Workers**:
   - Implement a service worker to cache pages or assets programmatically:

     ```javascript
     self.addEventListener('fetch', event => {
       event.respondWith(
         caches.match(event.request).then(response => {
           return response || fetch(event.request).then(networkResponse => {
             return caches.open('my-cache').then(cache => {
               cache.put(event.request, networkResponse.clone());
               return networkResponse;
             });
           });
         })
       );
     });
     ```

3. **Leverage Cache Storage API**:
   - Use the Cache Storage API to programmatically store responses:

     ```javascript
     caches.open('my-site-cache').then(cache => {
       cache.add('/static-page.html');
     });
     ```

### **Pros and Cons:**

| Pros                                   | Cons                                                     |
| -------------------------------------- | -------------------------------------------------------- |
| Reduces round-trips to the server      | Harder to manage and invalidate outdated content         |
| Improves performance for repeat visits | May lead to inconsistencies without proper cache busting |
| Leverages both browser and CDN cache   | Requires careful configuration to avoid stale data       |

### **Browser Cache x CDN Flow:**

1. User requests a page.
2. Browser checks local cache.
3. If not found, the request goes to the CDN.
4. CDN checks its cache and serves the page if found.
5. If not cached, the CDN fetches it from the origin server.

### **Best Practices**

- Use versioning or unique hashes in file names (e.g., `app.v1.2.js`) to force updates when content changes.
- Implement cache invalidation strategies to control when content should be updated.

## **Conclusion**

Combining these approaches offers a comprehensive caching strategy:

1. **CDN caching** for widely distributed, fast delivery of static assets.
2. **Static Site Generation** to reduce load on the server and improve scalability.
3. **Browser caching** to speed up repeat visits and reduce network requests.

These techniques, when used effectively, can dramatically enhance the performance and scalability of a web application while maintaining up-to-date content for users.
