#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> s(M); // 電球ごとの接続スイッチ
    for (int i = 0; i < M; ++i) {
        int k;
        cin >> k;
        s[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> s[i][j];
            s[i][j]--; // 0-indexed にする
        }
    }

    vector<int> p(M);
    for (int i = 0; i < M; ++i) {
        cin >> p[i];
    }

    int count = 0;

    // 2^N 通り全探索
    for (int bit = 0; bit < (1 << N); ++bit) {
        bool all_on = true;

        for (int i = 0; i < M; ++i) {
            int on_count = 0;
            for (int sw : s[i]) {
                if (bit & (1 << sw)) {
                    on_count++;
                }
            }
            if (on_count % 2 != p[i]) {
                all_on = false;
                break;
            }
        }

        if (all_on) count++;
    }

    cout << count << endl;
    return 0;
}
