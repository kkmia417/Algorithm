#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s,t;
    cin >> s >> t;

    int sum = 0;
    int res = 0;
    int ans = 0;

    for(int i = 0; i <= s; ++i){
        for(int j = 0; j <= s; ++j){
            for(int k = 0; k <= s; ++k){
                sum = i + j + k;
                res = i * j * k;
                if(sum > s || res > t){
                    continue;
                }
                else
                {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}