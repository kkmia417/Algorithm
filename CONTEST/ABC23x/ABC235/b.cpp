#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> h(n);

    for(int i = 0; i < n; ++i){
        cin >> h[i];
    }

    bool isRight = false;

    int ans = 0;

    while(!isRight){
        long long currentHeight = h[0];
        long long nextHeight = 0;

        for(int i = 0; i < n; ++i){
            nextHeight = h[i+1];

            if(!isRight && currentHeight < nextHeight){
                currentHeight = nextHeight;
                continue;
            }else{
                ans = i;
                isRight = true;
                break;
            }
        }
    }

    cout << h[ans] << endl;

    return 0;
}