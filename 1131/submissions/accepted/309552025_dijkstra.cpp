#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

struct edge{
	int from, to, weight;
	bool operator()(const edge &lhs, const edge &rhs){ // compare edges by weight
		return lhs.weight > rhs.weight;
	}
};

void dijkstra(const vector<vector<edge>> &edges, vector<int> &distance, int source){
	distance[source] = 0;
	priority_queue<edge, vector<edge>, edge> pq;
	for(const edge &e : edges[source]){
		pq.push(e);
	}
	while(!pq.empty()){
		edge e = pq.top();
		pq.pop();
		if(e.weight < distance[e.to]){
			distance[e.to] = e.weight;
			for(const edge &ed : edges[e.to]){
				pq.push({ed.from, ed.to, ed.weight + distance[e.to]});
			}
		}
	}
}

int main(){
	int n, m, u, v, w;
	scanf("%d %d %d %d %d", &n, &m, &u, &v, &w);
	vector<vector<edge>> edges(n);
	for(int i = 0; i < m; i++){
		int from, to, weight;
		scanf("%d %d %d", &from, &to, &weight);
		edges[from].push_back({from, to, weight});
	}
	vector<int> distance_from_u(n, INF), distance_from_v(n, INF), distance_from_w(n, INF);
	dijkstra(edges, distance_from_u, u);
	dijkstra(edges, distance_from_v, v);
	dijkstra(edges, distance_from_w, w);

	int ans = min(distance_from_u[v] + distance_from_v[w] + distance_from_w[u],
				  distance_from_u[w] + distance_from_w[v] + distance_from_v[u]);
	if(ans >= INF) ans = -1;
	printf("%d\n", ans);
}