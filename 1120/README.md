# 1120 . Assignment 11 - Longest Palindromic Subsequence

1. Dynamic Programming
    - dp[i][j]: 第 i 個字元到第 j 個字元之間的答案
      - = 0 if i > j
        - 字串是空的
      - = 1 if j >= i && j <= i + 1
        - 字串長度一或二
      - = d[i + 2][j - 2] + 2 if j > i + 1 && s[i] == s[j]
        - 頭尾相同
      - = max(d[i + 1][j], d[i][j - 1]) if j > i + 1 && s[i] != s[j]
        - 頭尾不相同
    - 最後答案是 dp[0][n - 1]

- [0756127_lps.c](submissions/accepted/0756127_lps.c)
- [309552025_lps.cpp](submissions/accepted/309552025_lps.cpp)

2. 和倒過來的 s（以下稱其為 r）做 LCS，修改遞迴式讓它不能用相鄰的字元
    - dp[i][j]: s 前 i 個字元和 r 前 j 個字元不用相鄰字元的 LCS 長度
      - = 0 if i < 0 || j < 0
        - 其中一個字串是空的
      - = d[i - 2][j - 2] + 1 if i >= 0 && j >= 0 && s[i] == r[j]
        - 當前字元相同
      - = max(d[i - 1][j], d[i][j - 1]) if i >= 0 && j >= 0 && s[i] != r[j]
        - 當前字元不同
    - 最後答案是 dp[n - 1][n - 1]

- [0756127_reversed_lcs.cpp](submissions/accepted/0756127_reversed_lcs.cpp)
- [309552025_reversed_lcs.cpp](submissions/accepted/309552025_reversed_lcs.cpp)
