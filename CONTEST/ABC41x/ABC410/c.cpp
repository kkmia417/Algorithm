#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> c(n + 2, 0);
    int ans = 0;

    for (int i = 0; i < q; ++i) {
        int a;
        cin >> a;

        ans -= (c[a - 1] == 0 && c[a] == 1);
        ans -= (c[a] == 0 && c[a + 1] == 1);
        
        c[a] = 1 - c[a];

        ans += (c[a - 1] == 0 && c[a] == 1);
        ans += (c[a] == 0 && c[a + 1] == 1);
        
        cout << ans << "\n";
    }

    return 0;
}