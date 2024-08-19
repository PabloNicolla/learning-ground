class Solution {
  /**
   * @param {number[]} nums
   * @param {number} k
   * @return {number[]}
   */
  topKFrequent(nums, k) {
    let freq = {};

    nums.forEach((num) => {
      freq[num] = (freq[num] || 0) + 1;
    });

    const sortedEntries = Object.entries(freq).sort(([, value1], [, value2]) => value2 - value1);
    const sortedKeys = sortedEntries.map((pair) => pair[0]);
    return sortedKeys.slice(0, k);
  }
}
