class Solution {
    public int[] productExceptSelf(int[] nums) {
        if (nums.length == 0) {
            return new int[]{};
        }
        int totalProduct = nums[0];
        int zeroCount = 0;
        int zeroIndex = 0;
        int[] output = new int[nums.length];

        if (nums[0] == 0) {
            ++zeroCount;
        }

        for (int i = 1; i < nums.length; ++i) {
            int num = nums[i];

            if (num == 0) {
                ++zeroCount;
                zeroIndex = i;
                if (zeroCount > 1) {
                    return output;
                }
            } else {
                totalProduct *= num;
            }
        }

        if (zeroCount == 1) {
            output[zeroIndex] = totalProduct;
            return output;
        }

        for (int i = 0; i < nums.length; ++i) {
            output[i] = totalProduct / nums[i];
        }

        return output;
    }
}  
