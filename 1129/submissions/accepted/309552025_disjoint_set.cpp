#include <bits/stdc++.h>
using namespace std;

class disjoint_set{
	public:
		disjoint_set(int size):boss(size), rank(size){
			for(int i = 0; i < size; i++){
				boss[i] = i;
				rank[i] = 1;
			}
		}

		int find(int x){
			return boss[x] == x ? x : (x = find(boss[x]));
		}

		void merge(int x, int y){
			x = find(x);
			y = find(y);
			if(x == y) return;
			if(rank[x] > rank[y]) swap(x, y);
			boss[x] = y;
			rank[y] += rank[x];
			rank[x] = 0;
		}

		int get_rank(int x){
			return rank[find(x)];
		}


	private:
		vector<int> boss; // the represent of the set
		vector<int> rank; // the size of the set
};

struct query{
	int u, v;
	bool is_add;

	query():is_add(false){}
};

int main(){
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	vector<vector<int>> edges(n, vector<int>(n));
	disjoint_set ds(n);

	for(int i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		if(u > v) swap(u, v);
		edges[u][v]++;
	}

	vector<query> querys(q);
	for(int i = 0; i < q; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		if(u > v) swap(u, v);
		querys[i].u = u;
		querys[i].v = v;

		if(u >= 0){
			if(edges[u][v] == 1) querys[i].is_add = true; // this operation effects the connectivity
			if(edges[u][v] > 0) edges[u][v] -= 1;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(edges[i][j])
	 			ds.merge(i, j);
		}
	}

	stack<int> ans;
	for(int i = q - 1; i >= 0; i--){
		if(querys[i].u < 0){
			ans.push(ds.get_rank(querys[i].v));
		}
		else{
			if(querys[i].is_add)
				ds.merge(querys[i].u, querys[i].v);
		}
	}

	while(!ans.empty()){
		printf("%d\n", ans.top());
		ans.pop();
	}
}