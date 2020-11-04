#include <bits/stdc++.h>
using namespace std;

class segment_tree{
	public:
		segment_tree(const vector<int> &arr):_size(arr.size()), st(arr.size() * 4){
			init(1, 0, _size - 1, arr);
		}
		void update(int pos, int val){
			update(1, 0, _size - 1, pos, val);
		}
		int query(int l, int r){
			return query(1, 0, _size - 1, l, r).total_max;
		}
	private:
		struct node{
			int total_max;
			int excluding_left;
			int excluding_right;
			int excluding_both;
			node():total_max(0), excluding_left(0), excluding_right(0), excluding_both(0) {}
		};
		int _size;
		vector<node> st;

		void init(int id, int l, int r, const vector<int> &arr){
			if(l == r){
				st[id].total_max = arr[l];
				st[id].excluding_left = st[id].excluding_right = st[id].excluding_both = 0;
				return;
			}
			int mid = (l + r) / 2;
			init(id * 2, l, mid, arr);
			init(id * 2 + 1, mid + 1, r, arr);
			st[id] = merge(st[id*2], st[id*2 + 1]);
		}

		void update(int id, int l, int r, int pos, int val){
			if(l == r){
				st[id].total_max = val;
				st[id].excluding_left = st[id].excluding_right = st[id].excluding_both = 0;
				return;
			}
			int mid = (l + r) / 2;
			if(pos <= mid) update(id * 2, l, mid, pos, val);
			else update(id * 2 + 1, mid + 1, r, pos, val);
			st[id] = merge(st[id*2], st[id*2 + 1]);
		}

		node query(int id, int l, int r, int L, int R){
			if(r < L || R < l) return node();
			if(L <= l && r <= R) return st[id];
			int mid = (l + r) / 2;
			return merge(query(id * 2, l, mid, L, R), query(id * 2 + 1, mid + 1, r, L, R));
		}

		node merge(const node &left, const node &right){
			node result;
			result.total_max = max(left.excluding_right + right.total_max, left.total_max + right.excluding_left);
			result.excluding_left = max(left.excluding_left + right.excluding_left, left.excluding_both + right.total_max);
			result.excluding_right = max(left.excluding_right + right.excluding_right, left.total_max + right.excluding_both);
			result.excluding_both = max(left.excluding_left + right.excluding_both, left.excluding_both + right.excluding_right);
			return result;
		}
};

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> arr(n);
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
	segment_tree st(arr);
	while(m--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(!a) st.update(b, c);
		else printf("%d\n", st.query(b, c));
	}
}