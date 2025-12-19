#include <bits/stdc++.h>
using namespace std;

// もう一回
int main() {
    int n;
    cin >> n;

    set<pair<string, string>> names;

    for (int i = 0; i < n; ++i) {
        string s, t;
        cin >> s >> t;

        pair<string, string> full_name = {s, t};

        if (names.count(full_name)) {
            cout << "Yes" << endl;
            return 0;
        }

        names.insert(full_name);
    }

    cout << "No" << endl;
    return 0;
}
