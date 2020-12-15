#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	int block = sqrt(n);

	vector<int> v(n), blocks(block + 1, INT_MIN);
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);

		int id = i / block;
		blocks[id] = max(blocks[id], v[i]);
	}

	while(m--){
		int i, j;
		scanf("%d %d", &i, &j);
		int ans = INT_MIN;
		int id[2] = {i / block, j / block};
		if(id[0] == id[1]){
			for(int x = i; x <= j; x++)
				ans = max(ans, v[x]);
		}
		else{
			for(int x = id[0] + 1; x < id[1]; x++)
				ans = max(ans, blocks[x]);
			for(int x = i; x < block * (id[0] + 1); x++)
				ans = max(ans, v[x]);
			for(int x = block * id[1]; x <= j; x++)
				ans = max(ans, v[x]);
		}
		printf("%d\n", ans);
	}
}