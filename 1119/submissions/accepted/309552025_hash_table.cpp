#include <bits/stdc++.h>
using namespace std;

class hash_table{
	public:
		void add(const int& key, const tuple<int, int, int>& value){
			int index = hash(key);
			for(auto &it : table[index]){
				if(::get<0>(it) == key){
					if(value < it) it = value;
					return;
				}
			}
			table[index].push_back(value);
		}
		list<tuple<int, int, int>> get(const int& key){
			int index = hash(key);
			return table[index];
		}
		int hash(const int& key){
			return ((key % table_size) + table_size) % table_size;
		}
	private:
		static const int table_size = 1000041;
		list<tuple<int, int, int>> table[table_size];
};

hash_table mp;

vector<int> solve(const vector<int> &v, int s){
	
	tuple<int, int, int, int> ans{v.size(), v.size(), v.size(), v.size()};

	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < i; j++)
			mp.add(v[i] + v[j], make_tuple(v[i] + v[j], j, i));

		for(int j = i + 2; j < v.size(); j++){

			for(auto x : mp.get(s - v[i + 1] - v[j])){
				if(get<0>(x) != s - v[i + 1] - v[j]) continue;
				if(i + 1 == get<1>(x) || i + 1 == get<2>(x) || j == get<1>(x) || j == get<2>(x)) continue;
				tuple<int, int, int, int> temp = make_tuple(get<1>(x), get<2>(x), i + 1, j);
				if(temp < ans) ans = temp;;
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