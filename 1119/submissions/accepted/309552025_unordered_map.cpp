#include <bits/stdc++.h>
using namespace std;

vector<int> solve(const vector<int> &v, int s){
	unordered_map<int, pair<int, int>> mp; // key: sum of two numbers, value: key of two numbers
	tuple<int, int, int, int> ans{v.size(), v.size(), v.size(), v.size()};
	for(int i = 0; i < v.size(); i++){
		
		for(int j = 0; j < i; j++){

			pair<int, int> temp = make_pair(j, i);

			if(mp.find(v[i] + v[j]) == mp.end())
				mp.insert({v[i] + v[j], temp});
			else if(temp < mp[v[i] + v[j]])
				mp[v[i] + v[j]] = temp;
		}

		for(int j = i + 1; j < v.size(); j++){

			if(mp.find(s - v[i] - v[j]) == mp.end()) continue;

			pair<int, int> pr = mp[s - v[i] - v[j]];

			if(i == pr.first || i == pr.second || j == pr.first || j == pr.second) continue;
			tuple<int, int, int, int> temp{pr.first, pr.second, i, j};
			if(temp < ans) ans = temp;

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