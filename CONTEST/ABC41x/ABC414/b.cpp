#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<char, long long>> v(n);
    long long len = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        if (len <= 100) {
            len += v[i].second;
        }
    }

    if (len > 100) {
        cout << "Too Long" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (long long j = 0; j < v[i].second; j++) {
                cout << v[i].first;
            }
        }
        cout << endl;
    }

    return 0;
}