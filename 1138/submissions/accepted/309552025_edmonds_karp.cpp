#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

struct edge{
	int from, to, capacity;
};

class flow{
	public:
		// size: the number of normal vertices(without source and sink)
		// s: index of the source
		// t: index of the sink
		flow(int size, int s, int t):adj_list(size + 2), size(size + 2), s(s), t(t), f(0) {}

		void addedge(int from, int to, int capacity){
			adj_list[from].push_back({to, edges.size()});
			edges.push_back({from, to, capacity});

			adj_list[to].push_back({from, edges.size()});
			edges.push_back({to, from, 0});
		}

		int max_flow(){

			vector<int> dis, through;
			while(augmenting_path(dis, through)){
				int bottleneck = INF;
				int temp = t;
				while(temp != s){
					bottleneck = min(bottleneck, edges[through[temp]].capacity);
					temp = edges[through[temp]].from;
				}

				temp = t;
				while(temp != s){
					edges[through[temp]].capacity -= bottleneck;
					edges[through[temp]^1].capacity += bottleneck;
					temp = edges[through[temp]].from;
				}
				f += bottleneck;
			}

			return f;
		}

	private:
		vector<edge> edges;
		vector<vector<pair<int, int>>> adj_list; // vertex & edge number
		int size, s, t, f;

		bool augmenting_path(vector<int> &dis, vector<int> &through){
			
			dis = vector<int>(size, INF);
			through = vector<int>(size, -1);

			dis[s] = 0;
			queue<int> que;
			que.push(s);
			while(!que.empty()){
				int u = que.front();
				que.pop();
				for(auto &[v, e] : adj_list[u]){
					if(dis[v] > dis[u] + 1 && edges[e].capacity > 0){
						dis[v] = dis[u] + 1;
						through[v] = e;
						if(v == t) return true;
						que.push(v);
					}
				}
			}
			return false;
		}
};

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int s = n + m, t = n + m + 1;
	flow f(n + m, s, t);
	for(int i = 0; i < n; i++){
		int c;
		scanf("%d", &c);
		f.addedge(s, i, c);
	}
	int profit_sum = 0;
	for(int i = 0; i < m; i++){
		int p;
		scanf("%d", &p);
		profit_sum += p;
		f.addedge(n + i, t, p);
	}
	for(int i = 0; i < k; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		f.addedge(u, n + v, INF);
	}
	printf("%d\n", profit_sum - f.max_flow());

}