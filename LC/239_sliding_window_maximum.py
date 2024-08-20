from collections import deque


def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
    output = []
    deq = deque()

    for i in range(len(nums)):
        if deq and deq[0] < i - k + 1:
            deq.popleft()

        while deq and nums[deq[-1]] < nums[i]:
            deq.pop()

        deq.append(i)

        if i >= k - 1:
            output.append(nums[deq[0]])

    return output


# def maxSlidingWindow(nums: List[int], k: int) -> List[int]:
#     output = []
#     maxCount = 0
#     maxValue = None

#     for i in range(k):
#         if maxValue is None or nums[i] > maxValue:
#             maxValue = nums[i]
#             maxCount = 0
#         if maxValue == nums[i]:
#             maxCount += 1

#     output.append(maxValue)

#     for i in range(k, len(nums)):
#         startVal = nums[i - k]
#         newVal = nums[i]

#         if (maxValue < newVal):
#             maxValue = newVal
#             maxCount = 0

#         if (maxValue == newVal):
#             maxCount += 1

#         if (maxValue == startVal):
#             maxCount -= 1
#             if (maxCount == 0):
#                 maxValue = None
#                 for j in range(i - k + 1, i + 1):
#                     if maxValue is None or nums[j] > maxValue:
#                         maxValue = nums[j]
#                         maxCount = 0
#                     if maxValue == nums[j]:
#                         maxCount += 1

#         output.append(maxValue)

#     return output
