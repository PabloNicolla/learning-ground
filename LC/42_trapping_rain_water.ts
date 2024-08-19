function trap(height: number[]): number {
  let volume = 0;
  let leftIndex = 0;
  let rightIndex = height.length - 1;
  let leftMax = height[leftIndex];
  let rightMax = height[rightIndex];

  while (leftIndex < rightIndex) {
    const leftValue = height[leftIndex];
    const rightValue = height[rightIndex];

    if (leftValue > rightValue) {
      rightIndex--;
      volume += Math.max(Math.min(leftMax, rightMax) - height[rightIndex], 0);
      rightMax = Math.max(height[rightIndex], rightMax);
    } else {
      leftIndex++;
      volume += Math.max(Math.min(leftMax, rightMax) - height[leftIndex], 0);
      leftMax = Math.max(height[leftIndex], leftMax);
    }
  }

  return volume;
}
export {};
