from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_p, min_p, max_profit = prices[0], prices[0], 0

        for p in prices:
            if p < min_p:
                min_p = p
                max_p = p
            else:
                max_p = max(max_p, p)
            max_profit = max(max_profit, max_p-min_p)

        return max_profit
