#include <vector>
#include <unordered_map>
#include <queue>

constexpr int FEED_MAX{10};

struct User;
struct Tweet;

struct Tweet
{
  static int shared_time;
  User *owner{};
  int id{};
  int createdAt{shared_time++};

  Tweet() = default;

  Tweet(const int id, User *const owner) : id{id}, owner{owner}
  {
  }

  constexpr bool operator<(const Tweet &other) const
  {
    return createdAt < other.createdAt;
  }
  constexpr bool operator>(const Tweet &other) const
  {
    return createdAt > other.createdAt;
  }
};

int Tweet::shared_time{0};

struct User
{
  std::vector<Tweet> tweets{};
  std::vector<int> feed{};
  std::unordered_map<int, User *> followers{};
  std::unordered_map<int, User *> following{};
  int id{};

  User() = default;

  User(const int id) : id{id}
  {
  }

  void postTweet(int tweetId)
  {
    const Tweet tweet{tweetId, this};
    tweets.push_back(tweet);
  }

  void addFollower(User *const newFollower)
  {
    followers[newFollower->id] = newFollower;
  }

  void follow(User *const userToFollow)
  {
    if (userToFollow == this)
      return;
    following[userToFollow->id] = userToFollow;
    userToFollow->addFollower(this);
  }

  void removeFollower(User *const follower)
  {
    followers.erase(follower->id);
  }

  void unfollow(User *const userToUnfollow)
  {
    if (userToUnfollow == this)
      return;
    following.erase(userToUnfollow->id);
    userToUnfollow->removeFollower(this);
  }

  void updateFeed()
  {
    feed.clear();
    std::priority_queue<Tweet> firstTweetFromEach{};
    std::unordered_map<User *, int> users_tweetIndex{};

    if (!tweets.empty())
    {
      users_tweetIndex[this] = static_cast<int>(tweets.size()) - 1;
      firstTweetFromEach.push(tweets[tweets.size() - 1]);
    }

    for (const auto &[followeeId, followee] : following)
    {
      if (!followee->tweets.empty())
      {
        users_tweetIndex[followee] = static_cast<int>(followee->tweets.size()) - 1;
        firstTweetFromEach.push(followee->tweets[users_tweetIndex[followee]]);
      }
    }

    while (!firstTweetFromEach.empty() && feed.size() < FEED_MAX)
    {
      Tweet newestTweet = firstTweetFromEach.top();
      feed.push_back(newestTweet.id);
      firstTweetFromEach.pop();
      if (--users_tweetIndex[newestTweet.owner] >= 0)
      {
        firstTweetFromEach.push(newestTweet.owner->tweets[users_tweetIndex[newestTweet.owner]]);
      }
    }
  }
};

class Twitter
{
  std::unordered_map<int, User> users{};

public:
  Twitter()
  {
  }

  void postTweet(int userId, int tweetId)
  {
    if (users.find(userId) == users.end())
    {
      users.emplace(userId, User(userId));
    }
    users[userId].postTweet(tweetId);
  }

  std::vector<int> getNewsFeed(int userId)
  {
    users[userId].updateFeed();
    return users[userId].feed;
  }

  void follow(int followerId, int followeeId)
  {
    if (users.find(followerId) == users.end())
    {
      users.emplace(followerId, User(followerId));
    }
    if (users.find(followeeId) == users.end())
    {
      users.emplace(followeeId, User(followeeId));
    }

    users[followerId].follow(&users[followeeId]);
  }

  void unfollow(int followerId, int followeeId)
  {
    if (users.find(followerId) == users.end())
    {
      users.emplace(followerId, User(followerId));
    }
    if (users.find(followeeId) == users.end())
    {
      users.emplace(followeeId, User(followeeId));
    }

    users[followerId].unfollow(&users[followeeId]);
  }
};
