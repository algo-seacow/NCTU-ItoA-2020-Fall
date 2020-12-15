#include <stdio.h>
#include <stack>

int main(){
	int n;
	scanf("%d", &n);

	std::stack<int> st;
	for(int i = 0; i < n; i++){
		int a, ans;
		scanf("%d", &a);
		while(!st.empty() && a >= st.top()) st.pop();
		if(st.empty()) ans = -1;
		else ans = st.top();
		st.push(a);
		printf("%d%c", ans, " \n"[i==n-1]);
	}
}