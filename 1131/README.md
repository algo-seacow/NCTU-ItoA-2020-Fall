# 1131 . Assignment 17 - Shortest Closed Walk

分別以 u, v, w 為起點各自做一次 single-source shortest path，  
令 dis\[a\]\[b\] 為 a 到 b 的最短距離，  
答案為 min(dis\[u\]\[v\] + dis\[v\]\[w\] + dis\[w\]\[u\], dis\[u\]\[w\] + dis\[w\]\[v\] + dis\[v\]\[u\])  

- [309552025_dijkstra.cpp](submissions/accepted/309552025_dijkstra.cpp)