#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	string str;
	cin >> str;
	vector<vector<int>> dp(n + 2, vector<int>(n + 2));
	for(int i = n - 1; i >= 0; i--){
		dp[i][i] = 1;
		dp[i][i+1] = max(dp[i][i], dp[i+1][i+1]);
		for(int j = i + 2; j < n; j++){
			if(str[i] == str[j]){
				dp[i][j] = dp[i+2][j-2] + 2;
			}
			else{
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
			}
		}
	}
	printf("%d\n", dp[0][n-1]);
}