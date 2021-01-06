# 1138 . Assignment 19 - Maximum Profit

使用計算 maximum flow 的演算法，  
每個工具都視為一個點，  
源點有邊連至所有工具，容量為該工具的價格，  
每個產品都視為一個點，  
所有產品都有邊連至匯點，容量為該產品的 profit，  
如果 b 產品需要 a 工具，則從 a 連一條容量無限大的邊到 b。  

答案為全部的 profit 總和 減掉 maximum flow。  

- [309552025_edmonds_karp.cpp](submissions/accepted/309552025_edmonds_karp.cpp)