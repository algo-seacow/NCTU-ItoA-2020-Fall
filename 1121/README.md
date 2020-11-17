# 1121 . Assignment 12 - Shortest Interval Cover

若 n 個點已經由小到大排序了，重複把寬度 m 區間的左邊界放在還沒被 cover 到的最小的點即可確認寬度 m 是否可行。  
將 n 個點排序並且用 binary search 猜 m。

- [0756127_binary_search_greedy.c](submissions/accepted/0756127_binary_search_greedy.c)
