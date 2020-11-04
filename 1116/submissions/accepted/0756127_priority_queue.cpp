#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::priority_queue;

int n, a;
long long c;
priority_queue<int> q;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while (n--) {
    cin >> a;
    q.push(a);
  }
  q.push(0);

  while (q.size() > 1) {
    a = q.top();
    q.pop();
    a -= q.top();
    q.pop();
    if (a) {
      c += a;
      q.push(a);
    }
  }

  cout << c;

  return 0;
}

