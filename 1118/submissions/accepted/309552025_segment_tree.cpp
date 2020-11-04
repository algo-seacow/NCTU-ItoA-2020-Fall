#include <bits/stdc++.h>
using namespace std;

class segment_tree{
	public:
		segment_tree(const vector<int> &v):size(v.size()), v(v.size()*4){
			build(v, 1, 0, size - 1);
		}
		
		void update(int pos, int num){
			update(1, 0, size - 1, pos, num);
		}

		int query(int L, int R){
			if(L > R) return query(1, 0, size - 1, L, size - 1) + query(1, 0, size - 1, 0, R);
			else return query(1, 0, size - 1, L, R);
		}
	private:
		int size;
		vector<int> v;

		void build(const vector<int> &num, int id, int l, int r){
			if(l == r){
				v[id] = num[l];
				return;
			}
			int mid = (l + r) / 2;
			build(num, id * 2, l, mid);
			build(num, id * 2 + 1, mid + 1, r);
			v[id] = v[id * 2] + v[id * 2 + 1];
		}

		void update(int id, int l, int r, int pos, int num){
			if(l == r){
				v[id] = num;
				return;
			}
			int mid = (l + r) / 2;
			if(pos <= mid) update(id * 2, l, mid, pos, num);
			else update(id * 2 + 1, mid + 1, r, pos, num);
			v[id] = v[id * 2] + v[id * 2 + 1];
		}

		int query(int id, int l, int r, int L, int R){
			if(r < L || R < l) return 0;
			if(L <= l && r <= R) return v[id];
			int mid = (l + r) / 2;
			return query(id * 2, l, mid, L, R) + query(id * 2 + 1, mid + 1, r, L, R);
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
		int i, j, k;
		scanf("%d %d %d", &i, &j, &k);
		if(i == 0) st.update(j, k);
		else printf("%d\n", st.query(j, k));
	}
}