#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

long long p(long long b, long long e) {
    long long r = 1;
    b %= MOD;
    while (e > 0) {
        if (e % 2 == 1) r = (r * b) % MOD;
        b = (b * b) % MOD;
        e /= 2;
    }
    return r;
}

long long inv(long long n) {
    return p(n, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<int, pair<long long, int>> s;
    for (int i = 1; i <= n; ++i) {
        long long a;
        cin >> a;
        s[i] = {a, i};
    }

    for (int k = 0; k < m; ++k) {
        int l, r;
        cin >> l >> r;

        long long total = 0;
        vector<pair<int, pair<long long, int>>> add_q;
        vector<int> erase_q;
        
        auto it = s.upper_bound(l);
        if (it != s.begin()) {
            it--;
        }

        while (it != s.end() && it->first <= r) {
            int st = it->first;
            int en = it->second.second;
            long long v = it->second.first;

            if (en >= l) {
                erase_q.push_back(st);

                int i_st = max(l, st);
                int i_en = min(r, en);
                long long len = i_en - i_st + 1;
                total = (total + (v * len) % MOD) % MOD;

                if (st < l) {
                    add_q.push_back({st, {v, l - 1}});
                }
                if (en > r) {
                    add_q.push_back({r + 1, {v, en}});
                }
            }
            it++;
        }

        for (int key : erase_q) {
            s.erase(key);
        }
        for (const auto& pa : add_q) {
            s[pa.first] = pa.second;
        }

        long long inv_len = inv(r - l + 1);
        long long new_v = (total * inv_len) % MOD;
        s[l] = {new_v, r};
    }

    vector<long long> ans(n + 1);
    for (auto const& [st, pa] : s) {
        long long v = pa.first;
        int en = pa.second;
        for (int i = st; i <= en; ++i) {
            ans[i] = v;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << endl;

    return 0;
}