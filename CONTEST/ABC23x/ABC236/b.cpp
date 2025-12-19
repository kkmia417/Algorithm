#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int size = 4 * n - 1;
    vector<int> a(size);
    
    for (int i = 0; i < size; ++i) {
        cin >> a[i];
    }

    int ans = 0;

    for(int j = 1; j < n + 1; ++j){
        int in =  count(a.begin(),a.end(),j);
        if(in == 3){
            ans = j;
        }
    }

    cout << ans << endl;

    return 0;
}