class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i1 = 0
        i2 = len(numbers) - 1
        while (True):
            num_sum = numbers[i1] + numbers[i2]
            if num_sum == target:
                return [i1+1, i2+1]
            elif num_sum > target:
                i2 -= 1
            elif num_sum < target:
                i1 += 1
            elif i1 >= i2:
                return [-1, -1]
