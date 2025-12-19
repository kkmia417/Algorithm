#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    int m;
    cin >> n >> m;

    vector<pair<long long, long long>> v(m);
    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        v[i] = {a - b, a};
    }

    sort(v.begin(), v.end());

    long long s = 0;
    for (int i = 0; i < m; ++i) {
        long long c = v[i].first;
        long long a = v[i].second;

        if (n >= a) {
            long long k = 1 + (n - a) / c;
            s += k;
            n -= k * c;
        }
    }

    cout << s << endl;

    return 0;
}