#include <bits/stdc++.h>
using namespace std;

double W(double y) {
    double l = 0.5, r = 19.0;
    while(r - l > 1e-7){
    	double mid = (l + r) / 2;
    	if(mid * exp(mid) < y) l = mid;
    	else r = mid;
    }
    return (l + r) / 2.0;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        double y;
        cin >> y;
        cout << fixed << setprecision(12) << W(y) << '\n';
    }
    return 0;
}