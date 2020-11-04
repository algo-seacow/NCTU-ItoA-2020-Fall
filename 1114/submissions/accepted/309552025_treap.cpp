#include <bits/stdc++.h>
using namespace std;

default_random_engine generator;
uniform_int_distribution<int> distribution(0, INT_MAX);

class treap{
	public:
		treap():root(nullptr) {}
		~treap(){delete(root);}

		void insert(int value){
			insert(root, value);
		}

		int find_the_k_th_num(int k){
			return find_the_k_th_num(root, k);
		}

		int size() const{
			return root?root->size:0;
		}

	private:
		struct node{
			int value;
			int key; // random value for heap
			int count;
			int size;
			node *left, *right;

			node(int value):value(value), key(distribution(generator)), count(1), size(1), left(nullptr), right(nullptr) {}
			~node(){
				delete(left);
				delete(right);
			}
		}*root;

		void insert(node *&p, int value){
			if(!p) p = new node(value);
			else if(value == p->value){
				p->count++;
				p->size++;
			}
			else if(value < p->value){
				insert(p->left, value);
				update_size(p);

				if(p->key > p->left->key) rotate_right(p);
			}
			else if(value > p->value){
				insert(p->right, value);
				update_size(p);

				if(p->key > p->right->key) rotate_left(p);
			}
		}

		void rotate_left(node *&p){
			node *right = p->right;
			p->right = right->left;
			right->left = p;
			update_size(p);
			update_size(right);
			p = right;
		}

		void rotate_right(node *&p){
			node *left = p->left;
			p->left = left->right;
			left->right = p;
			update_size(p);
			update_size(left);
			p = left;
		}

		void update_size(node *&p){
			if(p) p->size = (p->left?p->left->size:0) + (p->right?p->right->size:0) + p->count;
		}

		int find_the_k_th_num(node *&p, int k){
			int left_size = p->left?p->left->size : 0;
			if(left_size >= k){
				return find_the_k_th_num(p->left, k);
			}
			else if(left_size + p->count >= k){
				return p->value;
			}
			else{
				return find_the_k_th_num(p->right, k - left_size - p->count);
			}
		}
};

int main(){
	int n, k;
	treap tr;
	scanf("%d %d", &n, &k);
	while(n--){
		int x;
		scanf("%d", &x);
		if(x) tr.insert(x);
		else{
			if(k != 0) printf("%d\n", tr.find_the_k_th_num((int)ceil(k / 100.0 * tr.size())));
			else printf("%d\n", tr.find_the_k_th_num(1));
		}
	}
}