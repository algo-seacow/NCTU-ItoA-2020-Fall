#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	long long ans = 0;
	make_heap(v.begin(), v.end());
	while(v.size() > 1){
		int largest = v.front();
		pop_heap(v.begin(), v.end()); v.pop_back();

		int second = v.front();
		pop_heap(v.begin(), v.end()); v.pop_back();
		
		ans += largest - second;
		if(largest != second){
			v.push_back(largest - second);
			push_heap(v.begin(), v.end());
		}
	}
	if(v.size() > 0) ans += v.front();
	printf("%lld\n", ans);
}