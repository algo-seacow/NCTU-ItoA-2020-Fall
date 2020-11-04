#include <bits/stdc++.h>
using namespace std;

bool test(const vector<int> &v, int column_limit){
	int row = 1, column = 0;
	column_limit++;
	for(int i = 0; i < v.size(); i++){
		if(column_limit - column >= v[i] + 1) column += v[i] + 1;
		else if(v[i] > column_limit - 1) return false;
		else{
			if(row >= 24) return false;
			row++;
			column = v[i] + 1;
		}
	}
	return true;
}

int main(){

	cin.tie(0);
	cin.sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		v[i] = s.size();
	}

	int l = -1, r = 2e5;
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(test(v, mid)) r = mid;
		else l = mid;
	}
	cout << r << '\n';
}