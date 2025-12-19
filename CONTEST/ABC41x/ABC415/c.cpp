#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int l = 1 << n;
        vector<bool> dp(l, false);
        dp[0] = true;

        for (int m = 1; m < l; ++m) {
            if (s[m - 1] == '1') {
                continue;
            }

            for (int i = 0; i < n; ++i) {
                if (m & (1 << i)) {
                    int p = m ^ (1 << i);
                    if (dp[p]) {
                        dp[m] = true;
                        break;
                    }
                }
            }
        }

        if (dp[l - 1]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}