#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    queue<pair<long long, long long>> q;

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            long long c, x;
            cin >> c >> x;
            q.push({c, x});
        } else {
            long long k;
            cin >> k;
            long long s = 0;

            while (k > 0) {
                long long c = q.front().first;
                long long x = q.front().second;
                
                long long t = min(k, c);
                
                s += t * x;
                k -= t;
                q.front().first -= t;
                
                if (q.front().first == 0) {
                    q.pop();
                }
            }
            cout << s << endl;
        }
    }

    return 0;
}