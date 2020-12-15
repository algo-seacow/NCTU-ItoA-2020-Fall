#include <bits/stdc++.h>
using namespace std;

int table[20][1000010];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		scanf("%d", &table[0][i]);

	for(int j = 1; (1 << j) <= n; j++){
		for(int i = 0; i + (1 << j) <= n ; i++){
			table[j][i] = max(table[j-1][i], table[j-1][i+(1<<(j-1))]);
		}
	}
	
	while(m--){
		int i, j;
		scanf("%d %d", &i, &j);
		int p = __lg(j - i + 1);
		printf("%d\n", max(table[p][i], table[p][j - (1 << p) + 1]));
	}
}