#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	priority_queue<int, vector<int>, greater<int>> min_pq;
	priority_queue<int> max_pq;
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		if(x == 0) printf("%d\n", max_pq.top());
		else if(max_pq.size() == 0) max_pq.push(x);
		else if(x <= max_pq.top()){
			max_pq.push(x);
			// a: max_pq.size()
			// b: min_pq.size()
			// (a-1)/(a+b) >= k / 100
			if(100 * (max_pq.size() - 1) >= k * (max_pq.size() + min_pq.size())){
				min_pq.push(max_pq.top());
				max_pq.pop();
			}
		} 
		else{
			min_pq.push(x);
			// a: max_pq.size()
			// b: min_pq.size()
			// a/(a+b) < k / 100
			if(100 * max_pq.size() < k * (max_pq.size() + min_pq.size())){
				max_pq.push(min_pq.top());
				min_pq.pop();
			}
		}
	}
}