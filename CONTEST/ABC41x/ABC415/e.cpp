#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w;
    cin >> h >> w;

    vector<vector<long long>> a(h, vector<long long>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    vector<long long> p(h + w - 1);
    for (int i = 0; i < h + w - 1; ++i) {
        cin >> p[i];
    }

    vector<vector<long long>> dp(h + 1, vector<long long>(w + 1, LLONG_MAX / 2));

    for (int i = h - 1; i >= 0; --i) {
        for (int j = w - 1; j >= 0; --j) {
            if (i == h - 1 && j == w - 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]);
            }
            
            int k = i + j;
            long long needed = dp[i][j];
            dp[i][j] = max(0LL, needed + p[k] - a[i][j]);
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}