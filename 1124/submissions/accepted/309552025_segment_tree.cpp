#include <bits/stdc++.h>
using namespace std;

class segment_tree{
	public:
		segment_tree(const vector<int> &data):v(data.size() * 4), size(data.size()) {
			build(data, 1, 0, size - 1);
		}

		int query(int L, int R){
			return query(1, 0, size - 1, L, R);
		}


	private:
		vector<int> v;
		int size;

		void build(const vector<int> &data, int id, int l, int r){
			if(l == r){
				v[id] = data[l];
				return;
			}
			int mid = (l + r) / 2;
			build(data, id * 2, l, mid);
			build(data, id * 2 + 1, mid + 1, r);
			v[id] = max(v[id * 2], v[id * 2 + 1]);
		}

		int query(int id, int l, int r, int L, int R){
			if(r < L || R < l) return INT_MIN;
			if(L <= l && r <= R) return v[id];
			int mid = (l + r) / 2;
			return max(query(id * 2, l, mid, L, R), query(id * 2 + 1, mid + 1, r, L, R));
		}
};

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> v(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	segment_tree st(v);
	while(m--){
		int i, j;
		scanf("%d %d", &i, &j);
		printf("%d\n", st.query(i, j));
	}
}