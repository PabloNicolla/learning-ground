class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> seen = new HashMap<>();

        for (int i = 0; i < nums.length; ++i) {
            int currNum = nums[i];
            if (seen.containsKey(target - currNum)) {
                return new int[] { seen.get(target - currNum), i };
            }
            seen.put(currNum, i);
        }
        return new int[] { -1, -1 };
    }
}
