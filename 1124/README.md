# 1124 . Quiz 1.2 - Range Maximum Query

用 Segment Tree 找最大值，注意最大值可能會是負的。  
由於這題輸入和輸出的量相當大，如果沒輸入優化可能會太慢，輸出請用 `'\n'` 或 `"\n"` 取代 `std::endl`。

- [0756127_segment_tree.c](submissions/accepted/0756127_segment_tree.c)
- [309552025_segment_tree.cpp](submissions/accepted/309552025_segment_tree.cpp)

附贈 Sparse Table 的解法。

- [0756127_sparse_table.c](submissions/accepted/0756127_sparse_table.c)
- [309552025_sparse_table.cpp](submissions/accepted/309552025_sparse_table.cpp)

分塊做法(後面兩筆可能 TLE)  
  - 將原先數列切成多塊區間，每塊大小為<img src="https://render.githubusercontent.com/render/math?math=\sqrt{n}">(除了最後一塊)，最多有<img src="https://render.githubusercontent.com/render/math?math=\lceil{\frac{n}{\sqrt{n}}}\rceil">塊區間。
  - 每塊各自先算出答案 (O(n))。
  - 查詢時若是跨過完整區塊則直接拿到那個區間的答案，若是非完整區間則重新計算答案，  
    最多有<img src="https://render.githubusercontent.com/render/math?math=\sqrt{n}">個完整區間及 2 個非完整區間，  
    非完整區間大小不超過<img src="https://render.githubusercontent.com/render/math?math=\sqrt{n}">，  
    因此單次查詢需時<img src="https://render.githubusercontent.com/render/math?math=O(\sqrt{n})">。

  - [309552025_block.cpp](submissions/TLE/309552025_block.cpp)