#include <bits/stdc++.h>
using namespace std;

struct enemy{
	int x, y;
	int direction; // 0:UP, 1:RIGHT, 2:DOWN, 3:LEFT
};

int bfs(const vector<vector<int>> &maze, int n, int m, int t){
	vector<enemy> enemies;
	vector<vector<bool>> available(n, vector<bool>(m)); // bool array(n * m)
	queue<pair<int, int>> que;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(maze[i][j] == 2) que.push(make_pair(i, j));
			else if(maze[i][j] >= 4) enemies.push_back({i, j, maze[i][j] - 4});
		}
	}

	int ans = 0;
	while(!que.empty() && ans < t){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				available[i][j] = (maze[i][j] != 0);
			}
		}
		for(int i = 0; i < enemies.size(); i++){
			int &x = enemies[i].x;
			int &y = enemies[i].y;
			int &direction = enemies[i].direction;
			available[x][y] = false; // there is an enemy at the time
			static int dx[4] = {-1, 0, 1, 0};
			static int dy[4] = {0, 1, 0, -1};
			if(x + dx[direction] >= 0 && x + dx[direction] < n &&
			   y + dy[direction] >= 0 && y + dy[direction] < m &&
			   maze[x + dx[direction]][y + dy[direction]])
			{
				x = x + dx[direction];
				y = y + dy[direction];
				available[x][y] = false; // there is an enemy at next time
			}
			else direction = (direction + 1) % 4;
		}
		
		int que_size = que.size();
		while(que_size--){
			static const int dx[5] = {0, 0, 0, 1, -1};
			static const int dy[5] = {0, 1, -1, 0, 0};
			pair<int, int> p = que.front();
			for(int i = 0; i < 5; i++){
				if(p.first + dx[i] < 0 || p.first + dx[i] >= n || p.second + dy[i] < 0 || p.second + dy[i] >= m) continue;
				if(available[p.first + dx[i]][p.second + dy[i]]){
					if(maze[p.first + dx[i]][p.second + dy[i]] == 3) return ans + 1;
					que.push(make_pair(p.first + dx[i], p.second + dy[i]));
					available[p.first + dx[i]][p.second + dy[i]] = false; // prevent for pushing the same point into queue again
				}
			}
			que.pop();
		}
		ans++;
	}
	return -1;
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
	printf("%d\n", bfs(maze, n, m, t));
}