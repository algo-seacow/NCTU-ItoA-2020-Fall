#include <bits/stdc++.h>
using namespace std;

struct item{
	int weight, volume, profit;
};

int dp[500][501][501];

int main(){
	int n, W, V;
	scanf("%d %d %d", &n, &W, &V);
	vector<item> items(n);
	for(int i = 0; i < n; i++){
		int w, v, p;
		scanf("%d %d %d", &w, &v, &p);
		items[i] = {w, v, p};
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j <= W; j++){
			for(int k = 0; k <= V; k++){
				if(j < items[i].weight || k < items[i].volume){
					if(i > 0) dp[i][j][k] = dp[i-1][j][k];
				}
				else{
					if(i > 0) dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-items[i].weight][k-items[i].volume] + items[i].profit);
					else dp[i][j][k] = items[i].profit;
				}
			}
		}
	}
	printf("%d\n", dp[n - 1][W][V]);

}