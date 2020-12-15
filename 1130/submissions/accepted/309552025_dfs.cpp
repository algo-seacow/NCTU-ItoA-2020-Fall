#include <bits/stdc++.h>
using namespace std;

struct enemy{
	int x, y;
	int direction; // 0:UP, 1:RIGHT, 2:DOWN, 3:LEFT
};

void dfs(const vector<vector<int>> &maze, vector<vector<vector<int>>> &available, int x, int y, int n, int m, int t, int &ans){
	if(t + 1 >= ans) return;
	static const int dx[5] = {1, -1, 0, 0, 0};
	static const int dy[5] = {0, 0, 1, -1, 0};
	for(int i = 0; i < 5; i++){
		if(x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m && available[t + 1][x + dx[i]][y + dy[i]]){
			if(maze[x + dx[i]][y + dy[i]] == 3) ans = t + 1;
			available[t + 1][x + dx[i]][y + dy[i]] = 0;
			dfs(maze, available, x + dx[i], y + dy[i], n, m, t + 1, ans);
		}
	}
}

int solve(const vector<vector<int>> &maze, int n, int m, int t){
	vector<enemy> enemies;
	vector<vector<vector<int>>> available(t + 1, vector<vector<int>>(n, vector<int>(m)));
	int sx, sy;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(maze[i][j] == 2) sx = i, sy = j;
			if(maze[i][j] >= 4) enemies.push_back({i, j, maze[i][j] - 4});
		}
	}
	for(int i = 1; i <= t; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				available[i][j][k] = (maze[j][k] != 0);
			}
		}
		static const int dx[4] = {-1, 0, 1, 0};
		static const int dy[4] = {0, 1, 0, -1};
		for(int j = 0; j < enemies.size(); j++){
			int &x = enemies[j].x;
			int &y = enemies[j].y;
			int &d = enemies[j].direction;
			available[i][x][y] = 0;
			if(x + dx[d] >=0 && x + dx[d] < n && y + dy[d] >=0 && y + dy[d] < m && maze[x + dx[d]][y + dy[d]] != 0){
				x = x + dx[d];
				y = y + dy[d];
			}
			else d = (d + 1) % 4;
			available[i][x][y] = 0;
		}
	}
	int ans = t + 1;
	dfs(maze, available, sx, sy, n, m, 0, ans);
	return ans > t ? -1 : ans;
}

int main(){
	int n, m, t;
	scanf("%d %d %d", &n, &m, &t);
	vector<vector<int>> maze(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &maze[i][j]);
		}
	}
	printf("%d\n", solve(maze, n, m, t));
}