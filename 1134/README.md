# 1134 . Quiz 2.2 - Range Mode Query

對於每次查詢 [l, r) 都直接去統計每個數字出現了幾次，  
由於每次區間都不重疊，整體所需時間為 O(n + m)。  

統計數字出現次數可以用 hash table，  
由於這題的數字都介於 [0, n)，所以也可以使用大小為 n 的 array 來統計，  
但是要注意不要每次 query 都重新建立大小為 n 的 array，否則需要時間會變為 O(nm)。  

- [309552025_hast_table.cpp](submissions/accepted/309552025_hast_table.cpp)
- [309552025_array.cpp](submissions/accepted/309552025_array.cpp)