#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l,r;
    cin >> l >> r;

    string s;
    cin >> s;

    // 1-indexed を 0-indexed に変換
    l--; r--;

    reverse(s.begin() + l, s.begin() + r + 1);

    cout << s << endl;

    return 0;
}