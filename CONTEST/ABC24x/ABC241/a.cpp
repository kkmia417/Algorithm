#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a(10);
    for(int i = 0; i < 10; ++i){
        cin >> a[i];
    }

    int count = 3;
    int ans = 0;
    int k = 0;

    while(count > 0){
        ans = a[k];
        k = ans;

        count--;
    }

    cout << ans << endl;

    return 0;
}