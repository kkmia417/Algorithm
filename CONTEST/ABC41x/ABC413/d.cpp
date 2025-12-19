#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        map<long long, int> cnt;
        bool dup = false;
        
        {
            map<long long, int> acnt;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
                cnt[a[i]]++;
                if (acnt.count(abs(a[i]))) {
                    dup = true;
                }
                acnt[abs(a[i])]++;
            }
        }

        if (dup) {
            if (cnt.size() > 2) {
                cout << "No\n";
                continue;
            }
            if (cnt.size() == 1) {
                cout << "Yes\n";
                continue;
            }
            
            auto it = cnt.begin();
            long long k1 = it->first;
            int c1 = it->second;
            it++;
            long long k2 = it->first;
            int c2 = it->second;
            
            if (k1 == -k2 && abs(c1 - c2) <= 1) {
                 cout << "Yes\n";
            } else {
                 cout << "No\n";
            }
            continue;
        }

        sort(a.begin(), a.end(), [](long long x, long long y) {
            return abs(x) < abs(y);
        });

        if (n <= 2) {
            cout << "Yes\n";
            continue;
        }

        long long p = a[1];
        long long q = a[0];
        bool ok = true;
        for (int i = 1; i < n - 1; ++i) {
            if (a[i+1] * q != a[i] * p) {
                ok = false;
                break;
            }
        }
        
        if (ok) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}