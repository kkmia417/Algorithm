#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    if (m >= n) {
        cout << 0 << endl;
        return 0;
    }

    sort(x.begin(), x.end());

    vector<long long> g;
    for (int i = 0; i < n - 1; ++i) {
        g.push_back(x[i + 1] - x[i]);
    }

    sort(g.begin(), g.end());

    long long ans = 0;
    for (int i = 0; i < n - m; ++i) {
        ans += g[i];
    }

    cout << ans << endl;

    return 0;
}