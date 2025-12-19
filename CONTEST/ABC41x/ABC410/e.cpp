#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <map>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 998244353;

    auto power = [&](long long b, long long e) -> long long {
        long long res = 1;
        b %= MOD;
        while (e > 0) {
            if (e % 2 == 1) res = (res * b) % MOD;
            b = (b * b) % MOD;
            e /= 2;
        }
        return res;
    };

    auto inv = [&](long long n) -> long long {
        return power(n, MOD - 2);
    };

    int n;
    cin >> n;

    map<int, vector<pair<int, int>>> mp;
    vector<int> vals;

    for (int i = 0; i < n; ++i) {
        vector<int> d(6);
        for (int j = 0; j < 6; ++j) {
            cin >> d[j];
            vals.push_back(d[j]);
        }
        sort(d.begin(), d.end());
        for (int j = 0; j < 6; ++j) {
            if (j > 0 && d[j] == d[j - 1]) continue;
            int v = d[j];
            int c = upper_bound(d.begin(), d.end(), v) - lower_bound(d.begin(), d.end(), v);
            mp[v].push_back({i, c});
        }
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    vector<long long> seg;
    int sn = 1;
    while (sn < n) sn *= 2;
    seg.assign(2 * sn, 1);

    function<void(int, long long, int, int, int)> upd_s;
    upd_s = [&](int idx, long long val, int x, int l, int r) {
        if (r - l == 1) {
            seg[x] = val;
            return;
        }
        int m = (l + r) / 2;
        if (idx < m) {
            upd_s(idx, val, 2 * x + 1, l, m);
        } else {
            upd_s(idx, val, 2 * x + 2, m, r);
        }
        seg[x] = (seg[2 * x + 1] * seg[2 * x + 2]) % MOD;
    };
    
    auto upd = [&](int idx, long long val) {
        upd_s(idx, val, 0, 0, sn);
    };

    long long inv6 = inv(6);
    vector<long long> cnts(n, 0);

    for(int i = 0; i < n; ++i) {
        upd(i, 0);
    }

    long long e = 0;
    long long pv = 0;

    for (int v : vals) {
        long long p_le = seg[0];
        long long p_gt = (1 - p_le + MOD) % MOD;
        e = (e + (long long)(v - pv) * p_gt) % MOD;

        for (auto const& p : mp[v]) {
            int idx = p.first;
            int num = p.second;
            cnts[idx] += num;
            upd(idx, (cnts[idx] * inv6) % MOD);
        }
        pv = v;
    }

    cout << e << endl;

    return 0;
}