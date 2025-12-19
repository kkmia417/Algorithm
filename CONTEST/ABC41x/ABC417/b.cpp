#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int b;
        cin >> b;

        auto it = find(a.begin(), a.end(), b);

        if (it != a.end()) {
            a.erase(it);
        }
    }

    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << (i == a.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}