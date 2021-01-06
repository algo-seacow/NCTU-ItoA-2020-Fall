#include<bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>> &edges, int s, vector<int> &visit, vector<int> &instack, vector<int> &low, stack<int> &st, int &t, vector<int> &constract){
	visit[s] = low[s] = ++t;
	st.push(s);
	instack[s] = true;
	for(const int &v : edges[s]){
		if(!visit[v]) dfs(edges, v, visit, instack, low, st, t, constract);
		if(instack[v]) low[s] = min(low[s], low[v]);
	}
	if(low[s] == visit[s]){
		while(!st.empty()){
			int top = st.top();
			instack[top] = false;
			constract[top] = s;
			st.pop();
			if(top == s) break;
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> edges(n);
	for(int i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		edges[u].push_back(v);
	}
	vector<int> visit(n), low(n), constract(n);
	vector<int> instack(n, false);
	int t = 0;
	stack<int> st;
	for(int i = 0; i < n; i++){
		if(!visit[i]) dfs(edges, i, visit, instack, low, st, t, constract);
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