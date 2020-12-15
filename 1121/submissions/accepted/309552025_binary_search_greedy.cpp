#include <bits/stdc++.h>
using namespace std;

bool test(const vector<int> &arr, int k, int length){
	int r = arr[0] + length;
	k--;
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] > r){
			r = arr[i] + length;
			k--;
		}
	}
	return k >= 0;
}

int main(){

	int n, k;
	scanf("%d%d", &n, &k);

	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr.begin(), arr.end());

	if(k == 1){
		printf("%d\n", arr.back() - arr.front());
		return 0;
	}

	// left bound: the largest number that won't be the answer
	// right bound: the smallest number that may be the answer
	int l = -1, r = (arr.back() - arr.front()) / 2;
	while(r > l + 1){
		int mid = l + (r - l) / 2;
		if(test(arr, k, mid)) r = mid;
		else l = mid;
	}

	printf("%d\n", r);
}