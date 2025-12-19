#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    set<string> us;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            us.insert(s[i] + s[j]);
        }
    }

    cout << us.size() << endl;

    return 0;
}