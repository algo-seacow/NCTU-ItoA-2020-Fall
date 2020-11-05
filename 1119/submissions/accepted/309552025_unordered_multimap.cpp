#include <bits/stdc++.h>
using namespace std;

vector<int> solve(const vector<int> &v, int s){
	unordered_multimap<int, pair<int, int>> mp; // key: sum of two numbers, value: key of two numbers
	tuple<int, int, int, int> ans{v.size(), v.size(), v.size(), v.size()};
	for(int i = 0; i < v.size(); i++){
		
		for(int j = 0; j < i; j++)
			mp.insert({v[i] + v[j], {j, i}});

		for(int j = i + 1; j < v.size(); j++){

			if(mp.find(s - v[i] - v[j]) == mp.end()) continue;

			auto its = mp.equal_range(s - v[i] - v[j]);

			for(auto it = its.first; it != its.second; it++){
				if(i == it->second.first || i == it->second.second || j == it->second.first || j == it->second.second) continue;
				tuple<int, int, int, int> temp{it->second.first, it->second.second, i, j};
				if(temp < ans) ans = temp;
			}
		}
	}
	if(get<0>(ans) != v.size()) return vector<int>{get<0>(ans), get<1>(ans), get<2>(ans), get<3>(ans)};
	return vector<int>{-1};
}

int main(){
	int n, s;
	scanf("%d %d", &n, &s);
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	vector<int> ans = solve(v, s);
	for(int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i], " \n"[i==ans.size()-1]);
	
}