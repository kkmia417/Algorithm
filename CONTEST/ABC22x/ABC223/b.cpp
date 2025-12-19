#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    string s1 = s;
    string s2 = s;

    for(int i = 0; i < s.size(); ++i){
        rotate(s.begin(), s.begin() + 1, s.end());
        s1 = min(s1, s);
        s2 = max(s2, s);
    }

    cout << s1 << endl;
    cout << s2 << endl;

    return 0;
}