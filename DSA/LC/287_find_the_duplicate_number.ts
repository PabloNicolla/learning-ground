// O(n) Memory(1)
function findDuplicate(nums: number[]): number {
  let fast = nums[0];
  let slow = nums[0];

  do {
    fast = nums[nums[fast]];
    slow = nums[slow];
  } while (fast != slow);

  let slow2 = nums[0];

  while (slow2 != slow) {
    slow2 = nums[slow2];
    slow = nums[slow];
  }

  return slow2;
}

console.log(findDuplicate([1, 3, 4, 2, 2]));
