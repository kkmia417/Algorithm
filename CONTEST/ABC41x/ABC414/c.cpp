#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long a, n;
    cin >> a >> n;

    long long sum = 0;

    for (long long k = 1; ; ++k) {
        string s = to_string(k);
        string t = s;
        reverse(t.begin(), t.end());

        long long p1;
        try {
            p1 = stoll(s.substr(0, s.length() - 1) + t);
        } catch (...) {
            break;
        }

        if (p1 > n) {
            break;
        }

        vector<int> d1;
        long long temp1 = p1;
        while (temp1 > 0) {
            d1.push_back(temp1 % a);
            temp1 /= a;
        }
        bool ok1 = true;
        for (int i = 0; i < d1.size() / 2; ++i) {
            if (d1[i] != d1[d1.size() - 1 - i]) {
                ok1 = false;
                break;
            }
        }
        if (ok1) {
            sum += p1;
        }

        long long p2;
        try {
            p2 = stoll(s + t);
        } catch (...) {
            break;
        }

        if (p2 <= n) {
            vector<int> d2;
            long long temp2 = p2;
            while (temp2 > 0) {
                d2.push_back(temp2 % a);
                temp2 /= a;
            }
            bool ok2 = true;
            for (int i = 0; i < d2.size() / 2; ++i) {
                if (d2[i] != d2[d2.size() - 1 - i]) {
                    ok2 = false;
                    break;
                }
            }
            if (ok2) {
                sum += p2;
            }
        }
    }

    cout << sum << endl;

    return 0;
}