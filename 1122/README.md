# 1122 . Assignment 13 - Knapsack with Volumes

- 和 Knapsack 差不多，只是多一個維度來算 Volume。
  - `dp[i][j][k]`: 前 `i` 個物品在 `W = j` 和 `V = k` 的限制下最大的 profit。
    - `0` if `i < 0`
      - 沒東西可以選
    - `dp[i - 1][j][k]` if `i >= 0 && (j < w[i] || k < v[i])`
      - 放不下第 `i` 個物品
    - `max(dp[i - 1][j][k], dp[i - 1][j - w[i]][k - v[i]] + p[i])` if `i >= 0 && j >= w[i] && k >= v[i]`
      - 放不放第 `i` 個物品都試過
  - 最後答案在 `dp[n - 1][W][V]`。
- [0756127_knapsack.c](submissions/accepted/0756127_knapsack.c)
- [309552025_knapsack.cpp](submissions/accepted/309552025_knapsack.cpp)

- 和前一個做法類似，但可以觀察到 `dp[i - 2][*][*]` 以前是不會在用到的。
  - 只留下 `dp[i][*][*]` 和 `dp[i - 1][*][*]`。
    - 實作上只用 `dp[0][*][*]` 和 `dp[1][*][*]` 兩個交替使用。
  - 最後答案在 `dp[((n - 1) & 1)][W][V]`。
- [309552025_knapsack_rolling_array.cpp](submissions/accepted/309552025_knapsack_rolling_array.cpp)