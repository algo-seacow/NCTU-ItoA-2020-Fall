# 1122 . Assignment 13 - Knapsack with Volumes

- 和 Knapsack 差不多，只是多一個維度來算 Volume。
  - `dp[i][j][k]`: 前 `i` 個物品在 `W = j` 和 `V = k` 的限制下最大的 profit。
    - `0` if `i < 0`
      - 沒東西可以選
    - `dp[i - 1][j][k]` if `i >= 0 && (j < w[i] || k < v[i])`
      - 放不下第 `i` 個物品
    - `max(dp[i - 1][j][k], dp[i - 1][j - w[i]][k - v[i]] + p[i])` if `i >= 0 && j >= w[i] && k >= v[i]`
      - 放不放第 `i` 個物品都試過
- [0756127_knapsack.c](submissions/accepted/0756127_knapsack.c)
