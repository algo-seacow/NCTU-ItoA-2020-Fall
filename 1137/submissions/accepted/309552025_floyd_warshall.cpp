#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<vector<int>> dp(n, vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &dp[i][j]);
			if(i == j) dp[i][j] = 0;
			else if(dp[i][j] == 0) dp[i][j] = INF;
		}
	}

	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d%c", dp[i][j] >= INF? -1 : dp[i][j], " \n"[j==n-1]);
		}
	}
}