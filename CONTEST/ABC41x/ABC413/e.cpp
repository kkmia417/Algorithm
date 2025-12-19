#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sz = 1 << n;
        vector<int> p(sz);
        for (int i = 0; i < sz; ++i) {
            cin >> p[i];
        }

        for (int k = 1; k <= n; ++k) {
            int bs = 1 << k;
            int hs = 1 << (k - 1);
            for (int i = 0; i < sz; i += bs) {
                if (p[i] > p[i + hs]) {
                    for (int j = 0; j < hs; ++j) {
                        swap(p[i + j], p[i + hs + j]);
                    }
                }
            }
        }

        for (int i = 0; i < sz; ++i) {
            cout << p[i] << (i == sz - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}