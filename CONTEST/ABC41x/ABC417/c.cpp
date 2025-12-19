#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<int, int> mp;
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        
        int target = i - v;
        if (mp.count(target)) {
            ans += mp[target];
        }

        int key = i + v;
        mp[key]++;
    }

    cout << ans << endl;

    return 0;
}