#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> d[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        long long sm = 0;
        bool f = true;
        for (int j = i; j < n - 1; ++j) {
            sm += d[j];
            if (!f) {
                cout << " ";
            }
            cout << sm;
            f = false;
        }
        cout << endl;
    }

    return 0;
}