#include <vector>

class Solution
{
public:
  int largestRectangleArea(std::vector<int> &heights)
  {
    std::vector<std::pair<int, int>> stack{};
    int maxArea{};
    int i = 0;
    int height;
    for (; i < heights.size(); ++i)
    {
      height = heights[i];
      while (!stack.empty() && stack.back().first > height)
      {
        int possibleNewMax = stack.back().first * (i - stack.back().second);
        if (possibleNewMax > maxArea)
        {
          maxArea = possibleNewMax;
        }
        stack.pop_back();
      }

      int j = i;
      int newHeightStartIndex = j;
      while (j > 0)
      {
        j--;
        if (heights[j] > height)
        {
          newHeightStartIndex--;
        }
        else if (heights[j] == height)
        { // height is already in the stack
          newHeightStartIndex = -1;
          break;
        }
        else
        {
          break; // current j_height is smaller
        }
      }

      if (newHeightStartIndex != -1)
        stack.push_back({height, newHeightStartIndex});
    }

    for (const auto &kv : stack)
    {
      int possibleNewMax = kv.first * (i - kv.second);
      if (possibleNewMax > maxArea)
      {
        maxArea = possibleNewMax;
      }
    }

    return maxArea;
  }
};

// Wrong Answer Attempt 1
//
// class Wrong_Answer_Attempt_1 {
// public:
//  int largestRectangleArea(std::vector<int>& heights) {
//    int maxArea{};
//    int minHeight{ std::numeric_limits<int>().max() };
//    int left = 0;
//    int right = heights.size() - 1;
//
//    std::vector<int> temp{};
//
//    std::function<void(int, int)> rec = [&](int l, int r) {
//      if (l >= r) return;
//
//      if (heights[l] > heights[r]) {
//        rec(l, r - 1);
//      }
//      else if (heights[l] < heights[r]) {
//        rec(l + 1, r);
//      }
//      else {
//        if (heights[l + 1] > heights[r - 1]) {
//          rec(l, r - 1);
//        }
//        else {
//          rec(l + 1, r);
//        }
//      }
//      int newMinHeight = std::min(heights[l], heights[r]);
//      if (minHeight > newMinHeight) {
//        minHeight = newMinHeight;
//      }
//      temp.push_back(minHeight);
//   };
//
//    rec(left, right);
//
//    int possibleMax{};
//    while (left < right) {
//      possibleMax = (right - left + 1) * temp.back();
//      temp.pop_back();
//      if (maxArea < possibleMax) {
//        maxArea = possibleMax;
//      }
//      if (heights[left] > heights[right]) {
//        right--;
//      }
//      else if (heights[left] < heights[right]) {
//        left++;
//      }
//      else {
//        if (heights[left + 1] > heights[right - 1]) {
//          right--;
//        }
//        else {
//          left++;
//        }
//      }
//    }
//
//    if (heights[left] > maxArea) {
//      maxArea = heights[left];
//    }
//
//    return maxArea;
//  }
//};

// Wrong Answer Attempt 2
//
// class Wrong_Answer_Attempt_2 {
// public:
//  int largestRectangleArea(std::vector<int>& heights) {
//    int maxArea{};
//    int minHeight{};
//    int left = 0;
//    int right = heights.size() - 1;
//
//    std::vector<int> temp{};
//
//    std::function<void()> rec = [&]() {
//        if (left == right) return;
//
//        if (heights[left] > heights[right]) {
//          right--;
//        }
//        else if (heights[left] < heights[right]) {
//          left++;
//        }
//        else {
//          if (heights[left + 1] > heights[right - 1]) {
//            right--;
//          }
//          else {
//            left++;
//          }
//        }
//
//        rec();
//      };
//
//    rec();
//
//    minHeight = heights[right];
//    int possibleMax{};
//
//    while (left >= 0 && right < heights.size()) {
//      minHeight = std::min(minHeight, std::min(heights[left], heights[right]));
//      possibleMax = (right - left + 1) * minHeight;
//      if (maxArea < possibleMax) {
//        maxArea = possibleMax;
//      }
//      if (right + 1 == heights.size()) {
//        --left;
//      }
//      else if (left == 0) {
//        ++right;
//      }
//      else if (left == right) {
//        if (heights[left - 1] > heights[right + 1]) {
//          left--;
//        }
//        else {
//          right++;
//        }
//      }
//      else {
//        if (heights[left] > heights[right]) {
//          right++;
//        }
//        else if (heights[left] < heights[right]) {
//          left--;
//        }
//        else {
//          if (heights[left - 1] > heights[right + 1]) {
//            left--;
//          }
//          else {
//            right++;
//          }
//        }
//      }
//    }
//
//    return maxArea;
//  }
//};