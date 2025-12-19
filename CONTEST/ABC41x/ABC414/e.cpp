#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    long long mod = 998244353;
    long long inv2 = 499122177;

    long long sq = 0;
    for (long long i = 1; i * i <= n; ++i) {
        sq = i;
    }

    long long ans = 0;

    for (long long b = 2; b <= sq; ++b) {
        long long q = n / b;
        long long r = n % b;
        long long t = ((b - 1) % mod * (q - 1 % mod + mod) % mod) % mod;
        t = (t + r) % mod;
        ans = (ans + t) % mod;
    }

    long long q_max = 0;
    if (sq < n) {
        q_max = n / (sq + 1);
    }

    for (long long q = 1; q <= q_max; ++q) {
        long long R = n / q;
        long long L = n / (q + 1);
        if (L < sq) {
            L = sq;
        }

        if (L >= R) continue;

        long long cnt = R - L;
        cnt %= mod;

        long long qm1 = (q - 1 + mod) % mod;

        long long sum_b_minus_1_num = L + R - 1;
        long long sum_b_minus_1 = (sum_b_minus_1_num % mod * cnt) % mod;
        sum_b_minus_1 = (sum_b_minus_1 * inv2) % mod;

        long long part1 = (qm1 * sum_b_minus_1) % mod;

        long long n_part = ((n % mod) * cnt) % mod;

        long long sum_b_num = L + 1 + R;
        long long sum_b = (sum_b_num % mod * cnt) % mod;
        sum_b = (sum_b * inv2) % mod;

        long long qb_part = ((q % mod) * sum_b) % mod;

        long long part2 = (n_part - qb_part + mod) % mod;
        
        long long term = (part1 + part2) % mod;
        ans = (ans + term) % mod;
    }

    cout << ans << endl;

    return 0;
}