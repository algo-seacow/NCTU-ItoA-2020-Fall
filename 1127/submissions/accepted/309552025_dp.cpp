#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	m -= n*k;
	int r = max(0, m);

	for(int i = 0; i < n; i++)
		v[i] *= (n - i);

	vector<int> dp(2 * r + 1);
	for(int i = 0; i < n; i++){
		for(int j = 2 * r; j >= v[i]; j--){
			dp[j] = max(dp[j - v[i]] + v[i], dp[j]);
		}
	}
	int ans = INT_MAX;
	for(int i = 0; i <= 2 * r; i++){
		if(abs(dp[i] - m) < ans) ans = abs(dp[i] - m);
	}
	printf("%d\n", ans);
} 
