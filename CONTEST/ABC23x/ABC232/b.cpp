#include <iostream>
#include <string>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    int n = S.size();
    int diff = (T[0] - S[0] + 26) % 26;

    for (int i = 1; i < n; ++i) {
        if ((T[i] - S[i] + 26) % 26 != diff) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}