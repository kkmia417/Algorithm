#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    // int ans = 0;

    // for(int i = 0; i < n; ++i){　// ループを最小限に
    //     if(n >= pow(2,i)) continue; // powはdouble型を返す

    //     ans = i - 1;
    //     break;
    // }

    // cout << ans << endl;

    int k = 0;

    // 2^k <= n を満たす最大の k を探す
    while ((1LL << (k + 1)) <= n) {
        k++;
    }

    cout << k << endl;

    return 0;
}