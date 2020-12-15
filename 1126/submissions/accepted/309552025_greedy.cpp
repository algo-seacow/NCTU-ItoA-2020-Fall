#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &v[i].first, &v[i].second);
	}

	sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b){
		if(a.second == b.second) return a.first < b.first;
		return a.second < b.second;
	});

	int ans = 0, act[2] = {0};
	for(int i = 0; i < n; i++){
		if(v[i].first >= act[0]){
			if(v[i].first >= act[1] && act[0] < act[1]){
				act[1] = v[i].second;
				ans++;
			}
			else{
				act[0] = v[i].second;
				ans++;
			}
		}
		else if(v[i].first >= act[1]){
			act[1] = v[i].second;
			ans++;
		}
	}
	printf("%d\n", ans);
}