#include <bits/stdc++.h>
using namespace std;

struct segment_tree{
	segment_tree(int size):size(size), st(size*4) {}
	void plus_one(int pos){
		update(1, 0, size - 1, pos);
	}
	int query(int l, int r){
		return query(1, 0, size - 1, l, r);
	}

	private:
		int size;
		vector<int> st;
		void update(int id, int l, int r, int pos){
			if(l == r){
				st[id]++;
				return;
			}
			int mid = (l + r) / 2;
			if(pos <= mid) update(id * 2, l, mid, pos);
			else update(id * 2 + 1, mid + 1, r, pos);
			st[id] = st[id * 2] + st[id * 2 + 1];
		}
		int query(int id, int l, int r, int L, int R){
			if(l > R || r < L || R < L) return 0;
			if(L <= l && r <= R) return st[id];
			int mid = (l + r) / 2;
			return query(id * 2, l, mid, L, R)
				 + query(id * 2 + 1, mid + 1, r, L, R);
		}
};

int main(){
	int n;
	scanf("%d", &n);
	vector<int> v(n), bigger(n), smaller(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	vector<int> dup(v);
	sort(dup.begin(), dup.end());
	dup.resize(unique(dup.begin(), dup.end()) - dup.begin()); // discretization

	segment_tree st(n);
	for(int i = 0; i < n; i++){
		int idx = lower_bound(dup.begin(), dup.end(), v[i]) - dup.begin();
		bigger[i] = st.query(idx + 1, dup.size() - 1); // query how many numbers which are greater than v[i] in a_{i}~a_{n-1} 
		st.plus_one(idx);
	}

	st = segment_tree(n);
	for(int i = n - 1; i >= 0; i--){
		int idx = lower_bound(dup.begin(), dup.end(), v[i]) - dup.begin();
		smaller[i] = st.query(0, idx - 1); // query how many numbers which are less than v[i] in a_{0}~a_{i-1}
		st.plus_one(idx);
	}

	long long ans = 0;
	for(int i = 0; i < n; i++){
		ans += (long long)bigger[i] * smaller[i];
		printf("%d %d %d\n", i+1, bigger[i], smaller[i]);
	}

	printf("%lld\n", ans);
}