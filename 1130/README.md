# 1130 . Assignment 16 - Shortest Manhattan Walk

- BFS
  - 每一秒做一次下列事項，最多做 t 秒
    - 用一份二維陣列紀錄哪些點是還可以走的(初始為非牆壁都是可以走的)
    - 所有 enemy 都移動並把移動前後的點都設成不能走
    - 處理 queue (玩家移動的角色)
      - 枚舉四個方向以及站在原地這五種情況
        - 如果不會走到迷宮外且是可以走的點
          - 如果是終點
            - 得到答案
          - 把新的點放入 queue 且把這個點設成不能走避免下次重複放進 queue
  - 超過 t 秒回傳 -1
  - 時間複雜度為 <img src="https://render.githubusercontent.com/render/math?math=O(n%20\times%20%20m%20\times%20t)">

- [309552025_bfs.cpp](submissions/accepted/309552025_bfs.cpp)

- DFS
  - 預先計算 t 秒內每秒哪些點是可以走的(共 n * m * t 個點)
  - 從起點開始遞迴 5 種選擇
  - 已經走過的點要設成不能走避免重複計算
  - 找到一種更好的解就更新答案
  - 可以搭配剪枝加速
  - 每個點最多走過一遍，時間複雜度為 <img src="https://render.githubusercontent.com/render/math?math=O(n%20\times%20%20m%20\times%20t)">

- [309552025_dfs.cpp](submissions/accepted/309552025_dfs.cpp)