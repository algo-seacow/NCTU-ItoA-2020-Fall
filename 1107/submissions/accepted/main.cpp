#include <bits/stdc++.h>
using namespace std;

int soda(int n, int k) {
    int ans = 0;
    while (n >= k) {
        ans += n / k;
        n = n / k + n % k;
    }
    return ans;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        int n, k;
        cin >> n >> k;
        cout << soda(n, k) << '\n';
    }
    return 0;
}
