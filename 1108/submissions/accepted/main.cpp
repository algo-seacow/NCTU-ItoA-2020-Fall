#include <bits/stdc++.h>
using namespace std;

int twoSum(vector<int> &a, int target) {
    int ans = 0;
    unordered_map<int, int> cnt;
    for (int x : a) {
        ans += cnt[target - x];
        cnt[x]++;
    }
    return ans;
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
