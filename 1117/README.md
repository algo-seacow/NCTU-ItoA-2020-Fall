# 1117 . Assignment 8 - Distinct Points

以下所有排序都是指 Counting Sort。
以 X 排序之後 X 一樣的會相鄰。  
再以 Y 排序，Y 一樣的會相鄰，XY 都一樣的也會相鄰。  
再以 Z 排序，Z 一樣的會相鄰，YZ 都一樣的也會相鄰，XYZ 都一樣的也會相鄰。  
再以 Z 排序，XZ 一樣的會相鄰。  
最後用排容原理就能算出每個點的答案。

- [0756127_radix_sort.c](submissions/accepted/0756127_radix_sort.c)
- [309552025_radix_sort.cpp](submissions/accepted/309552025_radix_sort.cpp)
