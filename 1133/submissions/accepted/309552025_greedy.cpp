#include <stdio.h>

int main(){
	
	int n;
	scanf("%d", &n);

	int ans = 0;
	bool last_choose = false;
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		if(a && !last_choose){
			ans++;
			last_choose = true;
		}
		else last_choose = false;
	}
	
	printf("%d\n", ans);
}