#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> degree(N + 1, 0); // 頂点番号は1から始まる

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
    }

    for (int i = 1; i <= N; ++i) {
        if (degree[i] == N - 1) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
