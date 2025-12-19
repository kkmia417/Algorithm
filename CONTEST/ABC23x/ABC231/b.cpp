#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }

    // 頻度をカウントするmap
    map<string,int> freq;

    for(string x : s) {
        freq[x]++;
    }

    string max_s = s[0];
    int max_count = 0;

    for(const auto& [value,count] :freq){
        if(count > max_count){
            max_count = count;
            max_s = value;
        }
    }

    cout << max_s << endl;

    return 0;
}