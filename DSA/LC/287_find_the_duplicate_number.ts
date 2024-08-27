// O(n) Memory(1)
function findDuplicate(nums: number[]): number {
  let fast = nums[0];
  let slow = nums[0];

  do {
    fast = nums[nums[fast]];
    slow = nums[slow];
  } while (fast != slow);

  fast = nums[0];

  while (fast != slow) {
    fast = nums[fast];
    slow = nums[slow];
  }

  return fast;
}

console.log(findDuplicate([1, 3, 4, 2, 2]));
