#include <bits/stdc++.h>
using namespace std;

vector<int> solve(const vector<int> &v, int s){
	vector<tuple<int, int, int>> sum;
	sum.reserve(v.size() * (v.size() - 1));
	for(int i = 0; i < v.size(); i++){
		for(int j = i + 1; j < v.size(); j++){
			sum.push_back(make_tuple(v[i] + v[j], i, j));
		}
	}
	sort(sum.begin(), sum.end());
	for(int i = 0; i < v.size(); i++){
		for(int j = i + 1; j < v.size(); j++){
			auto ans = *lower_bound(sum.begin(), sum.end(), make_tuple(s - v[i] - v[j], j + 1, 0));
			if(get<0>(ans) == s - v[i] - v[j])
				return vector<int>{i, j, get<1>(ans), get<2>(ans)};
		}
	}
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