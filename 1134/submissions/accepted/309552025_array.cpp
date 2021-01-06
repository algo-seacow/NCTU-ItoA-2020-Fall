#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	vector<int> cnt(n);
	while(m--){
		int l, r;
		scanf("%d %d", &l, &r);
		for(int i = l; i < r; i++)
			cnt[arr[i]]++;

		pair<int, int> ans; // value & the number of the value occurs
		for(int i = l; i < r; i++){
			if((cnt[arr[i]] > ans.second) || (arr[i] < ans.first && cnt[arr[i]] == ans.second))
				ans = {arr[i], cnt[arr[i]]};
			cnt[arr[i]] = 0;
		}
		printf("%d\n", ans.first);
	}
}