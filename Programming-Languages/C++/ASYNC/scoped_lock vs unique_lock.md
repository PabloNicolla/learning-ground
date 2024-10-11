# scoped_lock vs unique_lock

## Code Snippet

```cpp
template <typename T>
class ThreadSafeQueue
{
public:
    void push_back(const T& item)
    {
        std::scoped_lock lock(muxQueue);
        deqQueue.emplace_back(std::move(item));

        std::unique_lock<std::mutex> ul(muxBlocking);
        cvBlocking.notify_one();
    }

    void push_front(const T& item)
    {
        std::scoped_lock lock(muxQueue);
        deqQueue.emplace_front(std::move(item));

        std::unique_lock<std::mutex> ul(muxBlocking);
        cvBlocking.notify_one();
    }

    bool empty()
    {
        std::scoped_lock lock(muxQueue);
        return deqQueue.empty();
    }

    size_t count()
    {
        std::scoped_lock lock(muxQueue);
        return deqQueue.size();
    }

    void clear()
    {
        std::scoped_lock lock(muxQueue);
        deqQueue.clear();
    }

    void wait()
    {
        while (empty())
        {
            std::unique_lock<std::mutex> ul(muxBlocking);
            cvBlocking.wait(ul);
        }
    }

protected:
    std::mutex muxQueue;
    std::deque<T> deqQueue;
    std::condition_variable cvBlocking;
    std::mutex muxBlocking;
};
```

## Code Explanation

- `push_front(const T& item):` This function adds an item to the front of a `std::deque` in a thread-safe manner and then notifies any waiting threads that an item has been added.
  - `std::scoped_lock lock(muxQueue);`
    - This locks the muxQueue mutex to ensure that the deque is modified safely in a multi-threaded environment. The scoped_lock ensures the mutex is locked for the duration of the function and automatically unlocks it when the function ends.
  - `deqQueue.emplace_front(std::move(item));`
    - This adds the item to the front of the deque.
  - `std::unique_lock<std::mutex> ul(muxBlocking);`
    - Here, a `std::unique_lock` is used to lock the muxBlocking mutex. The `std::unique_lock` provides more control over the lock, but in this case, it is used to ensure that `cvBlocking.notify_one()` has safe access to shared resources when notifying a waiting thread.
  - `cvBlocking.notify_one()`;
    - This notifies one waiting thread (if any) that an item has been added, signaling that it can stop waiting and continue processing.

- `wait()`: This function waits for an item to be added to the deque by blocking the thread if the deque is empty. It uses the condition variable to block and waits for a notification (notify_one).

  - `while (empty()):` This loops while the deque is empty.

  - `std::unique_lock<std::mutex> ul(muxBlocking);`
    - This locks the muxBlocking mutex. It needs to lock this mutex before calling `cvBlocking.wait(ul);`, as the condition variable requires the mutex to be locked before waiting.

  - `cvBlocking.wait(ul);`
    - This releases the lock on muxBlocking and blocks the thread until another thread calls `notify_one()` or `notify_all()`. Once notified, it re-acquires the lock and continues execution.

### Difference Between `std::scoped_lock` and `std::unique_lock`

- `std::scoped_lock`:
  - Simpler API: It's a simpler, RAII-style lock, introduced in C++17. It locks the mutexes immediately when constructed and unlocks them when it goes out of scope (at the end of the function or block).
  - Multiple Mutex Support: It supports locking multiple mutexes at once in a deadlock-free manner.
  - No Defer or Manual Unlocking: It does not provide flexibility for manually locking, unlocking, or deferring the lock. It's always locked immediately upon construction.

- Example:

```cpp
std::scoped_lock lock(muxQueue);  // Locks immediately
```

In your push_front function, `std::scoped_lock` is used because it’s a simple way to ensure that muxQueue is locked for the duration of the function and automatically unlocked when the function ends.

`std::unique_lock`:

- More Flexible: It provides more control over the lock than `std::scoped_lock`. You can defer locking (i.e., construct the lock without immediately acquiring it), unlock it manually, or even transfer ownership of the lock.
- Used with Condition Variables: `std::unique_lock` is required for use with condition variables like `std::condition_variable::wait()`, because condition variables temporarily release the lock when waiting and re-acquire it afterward. `std::scoped_lock` does not have the flexibility needed for this.

Example:

```cpp
std::unique_lock<std::mutex> ul(muxBlocking);  // Locks the mutex but with more flexibility
cvBlocking.wait(ul);  // Unlocks mutex while waiting and re-locks after notification
```

- In your `wait()` function, `std::unique_lock` is used because it’s necessary to work with `std::condition_variable::wait()`. This function needs to release the lock while waiting and then re-acquire it when signaled, and `std::unique_lock` provides this functionality.

## Summary

- Use `std::scoped_lock` when you need a simple lock that automatically locks and unlocks a mutex within a scope. It's useful when you don't need extra control over the lock and just want to guarantee the mutex is safely locked and unlocked.

- Use `std::unique_lock` when you need more control over when the mutex is locked and unlocked, such as when working with condition variables. It allows for manual locking/unlocking and supports deferring the lock or temporarily releasing it, as required when waiting on a condition variable.
