import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> output = new ArrayList<>();
        Arrays.sort(nums);

        if (nums.length < 3) {
            return output;
        }

        for (int i = 0; i < nums.length - 2; ++i) {
            int num = nums[i];

            if (num > 1) {
                break;
            }

            if (i > 0 && nums[i - 1] == num) {
                continue;
            }

            int head = i + 1;
            int tail = nums.length - 1;

            while (head < tail) {
                int threeSum = nums[head] + nums[tail] + num;
                if (threeSum == 0) {
                    output.add(new ArrayList<>(Arrays.asList(num, nums[head], nums[tail])));
                    while (head < tail && nums[head] == nums[head + 1]) {
                        head += 1;
                    }
                    head += 1;

                    while (head < tail && nums[tail] == nums[tail - 1]) {
                        tail -= 1;
                    }
                    tail -= 1;

                } else if (threeSum > 0) {
                    tail -= 1;
                } else {
                    head += 1;
                }
            }
        }

        return output;
    }
}
