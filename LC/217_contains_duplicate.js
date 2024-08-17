class Solution {
  /**
   * @param {number[]} nums
   * @return {boolean}
   */
  hasDuplicate(nums) {
    nums.sort((x, y) => x - y);
    for (let i = 1; i < nums.length; ++i) {
      if (nums[i - 1] === nums[i]) return true;
    }
    return false;
  }
}
