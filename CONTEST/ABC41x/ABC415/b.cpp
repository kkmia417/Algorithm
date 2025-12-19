#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> p;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '#') {
            p.push_back(i + 1);
        }
    }

    for (int i = 0; i < p.size(); i += 2) {
        cout << p[i] << "," << p[i + 1] << endl;
    }

    return 0;
}