#include <bits/stdc++.h>
using namespace std;

class segment_tree{
	public:
		segment_tree(int size):st_size(size), v(size*4){}
		void add_one(int pos){
			add_one(1, 0, st_size - 1, pos);
		}
		int query_k_th_num(int k){
			return query(1, 0, st_size - 1, k);
		}
		int size(){
			return v[1];
		}

	private:
		int st_size;
		vector<int> v;
		void add_one(int id, int l, int r, int pos){
			if(l == r){
				v[id]++;
				return;
			}
			int mid = (l + r) / 2;
			if(pos <= mid) add_one(id * 2, l, mid, pos);
			else add_one(id * 2 + 1, mid + 1, r, pos);
			v[id] = v[id * 2] + v[id * 2 + 1];
		}
		int query(int id, int l, int r, int k){
			if(l == r) return l;
			int mid = (l + r) / 2;
			if(k > v[id * 2]) return query(id * 2 + 1, mid + 1, r, k - v[id * 2]);
			else return query(id * 2, l, mid, k);
		}
};

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> input(n), number;
	for(int i = 0; i < n; i++){
		scanf("%d", &input[i]);
		if(input[i] != 0) number.push_back(input[i]);
	}
	sort(number.begin(), number.end());
	number.resize(unique(number.begin(), number.end()) - number.begin());

	segment_tree st(number.size());
	for(int i = 0; i < n; i++){
		if(input[i] == 0){
			int index;
			if(k != 0) index = st.query_k_th_num((int)ceil(k / 100.0 * st.size()));
			else index = st.query_k_th_num(1);
			printf("%d\n", number[index]);
		}
		else{
			int index = lower_bound(number.begin(), number.end(), input[i]) - number.begin();
			st.add_one(index);
		}
	}
}