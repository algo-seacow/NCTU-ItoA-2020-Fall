#include <stdio.h>
#include <vector>
#include <stack>
#define checkboard(x, y, n, m) ((x >= 0) && (x < n) && (y >= 0) && (y < m))
using namespace std;

class disjoint_set{
	public:
		disjoint_set(int n, int m):boss(n*m), n(n), m(m){
			for(int i = 0; i < n * m; i++)
				boss[i] = i;
		}

		void merge(int x1, int y1, int x2, int y2){
			merge(x1 * m + y1, x2 * m + y2);
		}

		int find(int x, int y){
			return find(x * m + y);
		}

	private:
		vector<int> boss;
		int n, m;

		void merge(int x, int y){
			x = find(x);
			y = find(y);
			if(x != y) boss[x] = y;
		}

		int find(int x){
			return boss[x] = (x == boss[x]? x : find(boss[x]));
		}
};

struct operation{
	int a, b, c, d;
};

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	vector<vector<int>> maze(n, vector<int>(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &maze[i][j]);

	vector<operation> ops(k);
	for(int i = 0; i < k; i++){
		auto &[a, b, c, d] = ops[i];
		scanf("%d", &a);
		if(a < 0){
			scanf("%d %d", &c, &d);
			maze[c][d]--;
		}
		else scanf("%d %d %d", &b, &c, &d);
	}

	disjoint_set ds(n, m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(maze[i][j] == 1){
				if(checkboard(i, j + 1, n, m) && maze[i][j+1] == 1) ds.merge(i, j, i, j + 1);
				if(checkboard(i + 1, j, n, m) && maze[i+1][j] == 1) ds.merge(i, j, i + 1, j);
			}
		}
	}

	stack<int> ans;
	for(int i = k - 1; i >= 0; i--){
		auto &[a, b, c, d] = ops[i];
		if(a < 0){
			maze[c][d]++;
			if(maze[c][d] == 1){
				if(checkboard(c - 1, d, n, m) && maze[c-1][d] == 1) ds.merge(c - 1, d, c, d);
				if(checkboard(c + 1, d, n, m) && maze[c+1][d] == 1) ds.merge(c + 1, d, c, d);
				if(checkboard(c, d - 1, n, m) && maze[c][d-1] == 1) ds.merge(c, d - 1, c, d);
				if(checkboard(c, d + 1, n, m) && maze[c][d+1] == 1) ds.merge(c, d + 1, c, d);
			}
		}
		else{
			if(maze[a][b] < 1 || maze[c][d] < 1) ans.push(0);
			else ans.push(ds.find(a, b) == ds.find(c, d));
		}
	}

	while(!ans.empty()){
		printf("%d\n", ans.top());
		ans.pop();
	}

}