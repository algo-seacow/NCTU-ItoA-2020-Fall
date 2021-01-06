# 1136 . Quiz 2.4 - Strongly Connected Component Test

選定一個點作為起點進行 dfs (或 bfs)，  
檢查他是否可以走到全部的點，  
再用反向的邊進行一次 dfs (或 bfs)，  
檢查他在反向圖中是否可以走到全部的點(代表在原圖中其他點是否能走到起點)，  
如果兩次都能走到全部的點就代表整張圖是一個 SCC。  

- [309552025_dfs.cpp](submissions/accepted/309552025_dfs.cpp)