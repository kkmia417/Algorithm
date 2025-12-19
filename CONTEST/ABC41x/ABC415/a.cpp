#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> x;

    bool f = false;
    for (int v : a) {
        if (v == x) {
            f = true;
            break;
        }
    }

    if (f) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}