#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    bool ok = true;
    for (int i = 0; i < h - 1; ++i) {
        for (int j = 0; j < w - 1; ++j) {
            if (a[i][j] + a[i + 1][j + 1] > a[i + 1][j] + a[i][j + 1]) {
                ok = false;
                break;
            }
        }
        if (!ok) break;
    }

    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}
