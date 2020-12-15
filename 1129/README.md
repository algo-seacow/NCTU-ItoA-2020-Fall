# 1129 . Assignment 15 - Split Connected Components

- "第 k 個 graph 砍掉一條邊變成第 k+1 個 graph" 等價於 "第 k+1 個 graph 加上一條邊變成第 k 個 graph"。
- 利用 disjoint sets 來合併 connected components 及記錄 connected components 的大小。
  - 如果新增一條邊兩端連至不同的 connected component 則兩端會變同個 connected component。
  - 新的 connected component 大小為原來兩個大小相加。
- 先從題目初始給定的圖按照要求依序砍掉所有指定的邊，  
  過程中記錄哪次操作會讓兩點間原本只有 1 條邊變成 0 條邊 (其餘狀況不影響連通性)，  
  按照剩餘的邊利用 disjoint set 合併 connected components，  
  從最後面往前開始做題目要求的操作：
  - 查詢頂點 j 所屬的 connected component 大小
    - 透過 disjoint set 取得頂點 j 所屬的 connected component 並直接得到大小。
  - 刪除頂點 i 與頂點 j 之間的邊
    - 如果這次操作會影響連通性且頂點 i 與頂點 j 屬於不同的 connected component
      - 合併兩個所屬的 connected component

- [309552025_disjoint_set.cpp](submissions/accepted/309552025_disjoint_set.cpp)