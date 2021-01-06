#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	while(m--){
		int l, r;
		scanf("%d %d", &l, &r);
		unordered_map<int, int> cnt;
		for(int i = l; i < r; i++)
			cnt[arr[i]]++;

		pair<int, int> ans; // value & the number of the value occurs
		for(auto pr : cnt){
			if((pr.second > ans.second) || (pr.first < ans.first && pr.second == ans.second))
				ans = pr;
		}
		printf("%d\n", ans.first);
	}
}