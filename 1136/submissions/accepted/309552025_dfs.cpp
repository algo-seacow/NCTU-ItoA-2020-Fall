#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>> &edges, vector<int> &vis){
	vis[v] = true;
	for(auto x : edges[v]){
		if(!vis[x]){
			dfs(x, edges, vis);
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m;
		scanf("%d %d", &n, &m);
		vector<vector<int>> edges(n), redges(n);
		for(int i = 0; i < m; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			edges[u].push_back(v);
			redges[v].push_back(u);
		}

		bool ans = true;
		// dfs with original edges
		vector<int> vis(n, false);
		dfs(0, edges, vis);
		if(find(vis.begin(), vis.end(), false) != vis.end()){
			puts("0");
			continue;
		}

		// dfs with reversed edges
		vis = vector<int>(n, false);
		dfs(0, redges, vis);
		if(find(vis.begin(), vis.end(), false) != vis.end()){
			puts("0");
			continue;
		}
		puts("1");
	}
}