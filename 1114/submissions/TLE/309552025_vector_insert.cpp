#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v;
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		if(x == 0){
			if(k != 0) printf("%d\n", v[(int)ceil(k / 100.0 * v.size()) - 1]);
			else printf("%d\n", v[0]);
		}
		else{
			v.insert(lower_bound(v.begin(), v.end(), x), x);
		}
	}
}