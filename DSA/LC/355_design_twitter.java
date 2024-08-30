import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;

class Twitter {

  private int count;
  private Map<Integer, List<int[]>> tweetMap;
  private Map<Integer, Set<Integer>> followMap;

  public Twitter() {
    count = 0;
    tweetMap = new HashMap<>();
    followMap = new HashMap<>();
  }

  public void postTweet(int userId, int tweetId) {
    tweetMap.computeIfAbsent(userId, k -> new ArrayList<>()).add(new int[] { count--, tweetId });
  }

  public List<Integer> getNewsFeed(int userId) {
    List<Integer> res = new ArrayList<>();
    PriorityQueue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));

    followMap.computeIfAbsent(userId, k -> new HashSet<>()).add(userId);
    for (int followeeId : followMap.get(userId)) {
      if (tweetMap.containsKey(followeeId)) {
        List<int[]> tweets = tweetMap.get(followeeId);
        int index = tweets.size() - 1;
        int[] tweet = tweets.get(index);
        minHeap.offer(new int[] { tweet[0], tweet[1], followeeId, index });
      }
    }

    while (!minHeap.isEmpty() && res.size() < 10) {
      int[] curr = minHeap.poll();
      res.add(curr[1]);
      int index = curr[3];
      if (index > 0) {
        int[] tweet = tweetMap.get(curr[2]).get(index - 1);
        minHeap.offer(new int[] { tweet[0], tweet[1], curr[2], index - 1 });
      }
    }
    return res;
  }

  public void follow(int followerId, int followeeId) {
    followMap.computeIfAbsent(followerId, k -> new HashSet<>()).add(followeeId);
  }

  public void unfollow(int followerId, int followeeId) {
    followMap.computeIfPresent(followerId, (k, v) -> {
      v.remove(followeeId);
      return v;
    });
  }
}
