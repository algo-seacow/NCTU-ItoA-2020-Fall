#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct my_complex{
	long long real, imag;

	my_complex(long long real, long long imag):real(real), imag(imag){}

	my_complex operator *(const my_complex &rhs){
		return my_complex(real * rhs.real - imag * rhs.imag, real * rhs.imag + imag * rhs.real);
	}
	
	my_complex operator %(long long n){
		return my_complex((real % n + n) % n, (imag % n + n) % n);
	}
};

my_complex power(my_complex c, long long n){
	if(!n) return my_complex(1, 0);
	if(n&1) return power(c * c % MOD, n / 2) % MOD * c % MOD;
	else return power(c * c % MOD, n/2) % MOD;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		long long int a, b, n;
		scanf("%lld %lld %lld", &a, &b, &n);
		my_complex ans = power(my_complex(a % MOD, b % MOD), n);
		printf("%lld %lld\n", ans.real, ans.imag);
	}
}