#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

int n, a[200005], l[200005], r[200005];

long long f(int u) {
    if (!u) return 0;
    long long v = 0;
    if (l[u]) v = max(v, (long long)abs(u - l[u]) + f(l[u]));
    if (r[u]) v = max(v, (long long)abs(u - r[u]) + f(r[u]));
    return v;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    int rt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == n) rt = i;
    }

    stack<int> s;
    for (int i = 1; i <= n; i++) {
        int last = 0;
        while (!s.empty() && a[s.top()] < a[i]) {
            last = s.top();
            s.pop();
        }
        l[i] = last;
        if (!s.empty()) r[s.top()] = i;
        s.push(i);
    }

    cout << f(rt);
    return 0;
}