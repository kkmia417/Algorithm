#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long h, w;
    cin >> h >> w;

    vector<vector<long long>> a(h, vector<long long>(w)); // ここ

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    for (int j = 0; j < w; ++j) {
        for (int i = 0; i < h; ++i) {
            cout << a[i][j];
            if (i < h - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
