# 1127 . Quiz 1.5 - Productivity Programming

注意 `k * n >= m` 的情況答案就直接是全部都不選。

1. Dynamic Programming
    - `dp[i][j]`: 只有前 `i` 天能選擇的情況能不能在 `n` 天生產剛好 `j` 個產品，`j` 最大只需計算至 `2 * m - k * n - 1`。
      - = `false` if `j < k * n`
        - 總量比全部都不選還少
      - = `true` if `j = k * n`
        - 全部都不選
      - = `false` else `j > k * n && i < 0`
        - 沒得選
      - = `d[i - 1][j]` if `j > k * n && i >= 0 && j < k * n + a[i] * (n - i)`
        - 第 `i` 天開始產能增加 `a[i]` 會超過
      - = `d[i - 1][j] || d[i - 1][j - k * n - a[i] * (n - i)]` Otherwise
        - 加不加產能都試過
    - 最後答案是在 `dp[n - 1]` 這一行當中，和 `dp[n - 1][m]` 最近的 `true` 與其的距離。

- [0756127_dp_bool.c](submissions/accepted/0756127_dp_bool.c)

2. 另一種 Dynamic Programming
    - `dp[i][j]`: 只有前 `i` 天能選擇且 `m = j` 的答案。
      - = `abs(j - k * n)` if `i < 0 || j <= k * n`
        - 沒得選或全部都不選
      - = `d[i - 1][j]` if `i >= 0 && j > k * n && j <= k * n + a[i] * (n - i) / 2`
        - 增加產能不會有幫助所以不加
      - = `min(d[i - 1][j], d[i - 1][j - a[i] * (n - i)])` if `i >= 0 && j > k * n + a[i] * (n - i) / 2`
        - 加不加產能都試過
    - 最後答案是 `d[m]`。

- [0756127_dp.c](submissions/accepted/0756127_dp.c)
