#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    string t;
    cin >> t;

    string ans;

    for(int i = 0; i < t.size(); ++i){
        if(t[i] == '1'){
            ans += s1;
        }
        if(t[i] == '2'){
            ans += s2;
        }
        if(t[i] == '3'){
            ans += s3;
        }
    }

    cout << ans << endl;

    return 0;
}