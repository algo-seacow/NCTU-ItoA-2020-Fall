#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int y, b;
		scanf("%d %d", &y, &b);
		double l = 1, r = INT_MAX;
		for(int i = 0; i < 100; i++){
			double mid = (l + r) / 2;
			double test = mid * log(mid) / log(b);
			if(test > y) r = mid;
			else l = mid;
		}
		printf("%f\n", r);
	}
}