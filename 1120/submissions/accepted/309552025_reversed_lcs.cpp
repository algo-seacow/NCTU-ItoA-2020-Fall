#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	string str;
	cin >> str;
	string rev(str.rbegin(), str.rend());
	vector<vector<int>> dp(n, vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(str[i] == rev[j]){
				dp[i][j] = ((i > 1 && j > 1)? dp[i-2][j-2] : 0) + 1;
			}
			else{
				int l = j > 0 ? dp[i][j-1] : 0;
				int u = i > 0 ? dp[i-1][j] : 0;
				dp[i][j] = max(l, u);
			}
		}
	}
	printf("%d\n", dp[n-1][n-1]);
}