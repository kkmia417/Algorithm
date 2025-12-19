#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> p(n), a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> a[i] >> b[i];
    }

    const int max_p = 500;
    vector<vector<long long>> dp(n + 1, vector<long long>(max_p + 1, 0));

    int logn = (n > 0) ? floor(log2(n)) + 2 : 2;
    vector<vector<int>> nxt(logn, vector<int>(n + 1));
    vector<vector<long long>> sum_b(logn, vector<long long>(n + 1));

    auto solve = [&](int i, long long t) {
        if (t <= max_p) {
            return dp[i][t];
        }

        int ci = i;
        long long ct = t;

        for (int k = nxt.size() - 1; k >= 0; --k) {
            if (nxt[k][ci] < n) {
                long long bs = sum_b[k][ci];
                if (ct - bs > max_p) {
                    ct -= bs;
                    ci = nxt[k][ci];
                }
            }
        }
        
        while(ct > max_p && ci < n){
            ct = max(0LL, ct - b[ci]);
            ci++;
        }

        if (ct <= max_p) {
            return dp[ci][ct];
        } else {
            return ct;
        }
    };

    for (int t = 0; t <= max_p; ++t) {
        dp[n][t] = t;
    }

    for (int i = 0; i < n; ++i) {
        nxt[0][i] = i + 1;
        sum_b[0][i] = b[i];
    }
    nxt[0][n] = n;
    sum_b[0][n] = 0;

    for (int k = 1; k < logn; ++k) {
        for (int i = 0; i <= n; ++i) {
            int ni = nxt[k - 1][i];
            nxt[k][i] = nxt[k - 1][ni];
            sum_b[k][i] = sum_b[k - 1][i] + sum_b[k - 1][ni];
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int t = 0; t <= max_p; ++t) {
            long long ta;
            if (p[i] >= t) {
                ta = (long long)t + a[i];
            } else {
                ta = max(0LL, (long long)t - b[i]);
            }
            dp[i][t] = solve(i + 1, ta);
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        long long x;
        cin >> x;
        cout << solve(0, x) << "\n";
    }

    return 0;
}