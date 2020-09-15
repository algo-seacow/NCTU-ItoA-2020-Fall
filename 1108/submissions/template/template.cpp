#include <bits/stdc++.h>
using namespace std;

int twoSum(vector<int> &a, int target) {
    // TODO
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    cout << twoSum(a, target) << '\n';
}
