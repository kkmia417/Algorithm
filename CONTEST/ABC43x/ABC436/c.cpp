#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int &x : A) cin >> x;

    long long r = 1 + A[0] - 1;
    int ans = 1;

    for (int i = 1; i < N; ++i) {
        if (i + 1 <= r) {
            r = max(r, (long long)i + 1 + A[i] - 1);
            ans++;
        } else {
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}