# 1125 . Quiz 1.3 - Longest Common Subsequence

- 單純的 LCS。
  - `dp[i][j]`: `s1` 前 `i` 個字元和 `s2` 前 `j` 個字元的 LCS 長度
    - = `0` if `i < 0 || j < 0`
      - 其中一個字串是空的
    - = `d[i - 1][j - 1] + 1` if `i >= 0 && j >= 0 && s[i] == r[j]`
      - 當前字元相同
    - = `max(d[i - 1][j], d[i][j - 1])` if `i >= 0 && j >= 0 && s[i] != r[j]`
      - 當前字元不同
  - 最後答案是 `dp[n - 1][n - 1]`
- [0756127_lcs.c](submissions/accepted/0756127_lcs.c)
