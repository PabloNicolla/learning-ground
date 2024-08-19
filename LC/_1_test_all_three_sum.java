import java.util.*;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> output = new ArrayList<>();
        HashMap<Integer, Integer> pool = new HashMap<>();
        Arrays.sort(nums);
        for (int n : nums) {
            pool.put(n, pool.getOrDefault(n, 0) + 1);
        }
        int head = 0;
        int tail = nums.length - 1;
        removeFromPool(pool, nums[head]);
        removeFromPool(pool, nums[tail]);
        while (!pool.isEmpty()) {
            int currSum = nums[head] + nums[tail];
            if (pool.containsKey(-currSum)) {
                for (int i = 0; i < pool.get(-currSum); ++i) {
                    output.add(Arrays.asList(nums[head], -currSum, nums[tail]));
                }
                head += 1;
                removeFromPool(pool, nums[head]);
            } else if (currSum + nums[head + 1] > 0) {
                tail -= 1;
                removeFromPool(pool, nums[tail]);
            } else {
                head += 1;
                removeFromPool(pool, nums[head]);
            }
        }
        return output;
    }

    public void removeFromPool(Map<Integer, Integer> pool, int key) {
        if (pool.get(key) == 1) {
            pool.remove(key);
        } else {
            pool.put(key, pool.get(key) - 1);
        }
    }
}
