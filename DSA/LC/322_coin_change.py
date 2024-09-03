from typing import List


class Solution1:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0

        for a in range(1, amount + 1):
            for c in coins:
                if a >= c:
                    dp[a] = min(dp[a], 1 + dp[a - c])
        return dp[amount] if dp[amount] != amount + 1 else -1


class Solution2:
    def coinChange(self, coins: List[int], amount: int) -> int:

        if amount == 0:
            return 0

        temp = dict()

        # Recursive solution
        res = []

        def helper(partial_sum: int):

            if partial_sum == 0:
                return 0
            if partial_sum < 0:
                return -1

            if partial_sum in temp:
                return temp[partial_sum]

            min_coins = float('inf')
            for coin in coins:
                res = helper(partial_sum - coin)
                if res >= 0 and res < min_coins:
                    min_coins = res + 1  # Because result is for partial_sum - coin

            temp[partial_sum] = min_coins if min_coins != float('inf') else -1
            return temp[partial_sum]

        return helper(amount)
