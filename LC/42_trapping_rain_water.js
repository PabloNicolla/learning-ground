"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
function trap(height) {
  var volume = 0;
  var leftIndex = 0;
  var rightIndex = height.length - 1;
  var leftMax = height[leftIndex];
  var rightMax = height[rightIndex];
  while (leftIndex < rightIndex) {
    var leftValue = height[leftIndex];
    var rightValue = height[rightIndex];
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
