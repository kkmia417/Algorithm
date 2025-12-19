#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x;
    cin >> x;

    long long ans = x / 10;

    if(ans < 0 && x % 10 != 0)
    {
        ans = ans - 1;
    }

    cout << ans << endl;

    return 0;
}