#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s,t;
    cin >> s >> t;

    if(s == t) {
        cout << "Yes" << endl;
        return 0;
    }

    bool no = false;

    for(int i = 0; i < s.size(); ++i){
        if(s[i] == t[i])continue;

        swap(s[i],s[i+1]);

        if(s == t){
            no = true;
            break;
        }

        swap(s[i],s[i+1]);
    }

    if(no){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}