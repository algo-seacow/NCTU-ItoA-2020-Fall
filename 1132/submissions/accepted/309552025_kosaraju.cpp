#include<bits/stdc++.h>
using namespace std;

void dfs1(const vector<vector<int>> &edges, int s, vector<int> &visit, vector<int> &finish_time){
	visit[s] = true;
	for(const int &to : edges[s]){
		if(!visit[to]) dfs1(edges, to, visit, finish_time);
	}
	finish_time.push_back(s);
}

void dfs2(const vector<vector<int>> &edges, int s, vector<int> &visit, vector<int> &constract, int source){
	constract[s] = source;
	visit[s] = true;
	for(const int &to : edges[s]){
		if(!visit[to]) dfs2(edges, to, visit, constract, source);
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> edges(n), reversed_edges(n);
	for(int i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		edges[u].push_back(v);
		reversed_edges[v].push_back(u);
	}
	vector<int> finish_time, constract(n), visit(n, false);

	for(int i = 0; i < n; i++){
		if(!visit[i]) dfs1(edges, i, visit, finish_time);
	}
	visit = vector<int>(n, false);
	reverse(finish_time.begin(), finish_time.end());
	for(auto i : finish_time){
		if(!visit[i]) dfs2(reversed_edges, i, visit, constract, i);
	}

	vector<int> cnt(n);
	for(int i = 0; i < n; i++) cnt[constract[i]]++;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; i++){
		if(cnt[i]){
			pq.push(cnt[i]);
			if(pq.size() > 2) pq.pop();
		}
	}
	if(pq.size() == 1) puts("0");
	else printf("%d\n", pq.top());
}