function findDuplicate(nums: number[]): number {
  let seen: Set<number> = new Set();

  for (let num of nums) {
    if (seen.has(num)) return num;
    seen.add(num);
  }

  return -1;
}
