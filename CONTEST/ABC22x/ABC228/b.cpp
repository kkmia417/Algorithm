#include <iostream>
#include <vector>
using namespace std;

// ロジックがよくわかんないし問題もよくわかんない
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<bool> v(n, false);  // 秘密を知っているかどうか
    int cur = x - 1;           // インデックスに直す
    while (!v[cur]) {
        v[cur] = true;
        cur = a[cur] - 1;
    }

    int cnt = 0;
    for (bool b : v) if (b) ++cnt;

    cout << cnt << endl;
    return 0;
}
