from typing import List

class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        if k == 0 or n <= 1:
            return 0
        dp = [[0 for _ in range(n + 1)] for _ in range(k + 1)]
        for i in range(1, k + 1):
            max_so_far = float('-inf')
            for j in range(1, n + 1):
                max_so_far = max(max_so_far, dp[i - 1][j - 1] - prices[j - 1])
                dp[i][j] = max(dp[i][j - 1], prices[j - 1] + max_so_far)
        return dp[k][n]