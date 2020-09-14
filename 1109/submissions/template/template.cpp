#include <bits/stdc++.h>
using namespace std;

int findSingleton(vector<int> &a) {
    // TODO
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(2 * n - 1);
    for (int &x : a) {
        cin >> x;
    }
    cout << findSingleton(a) << '\n';
}
