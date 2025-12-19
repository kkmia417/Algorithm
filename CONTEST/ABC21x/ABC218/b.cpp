#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i < 26; ++i) {
        int p;
        cin >> p;
        // 'a' の ASCII 値に (p - 1) を足して英小文字に変換
        cout << static_cast<char>('a' + p - 1);
    }
    cout << endl;
    return 0;
}
