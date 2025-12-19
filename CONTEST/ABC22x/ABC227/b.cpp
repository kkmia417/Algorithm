#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    // 面積の集合を作る（a, b = 1 ～ 100まで試す）
    set<int> valid_areas;
    for (int a = 1; a <= 100; ++a) {
        for (int b = 1; b <= 100; ++b) {
            int area = 4 * a * b + 3 * a + 3 * b;
            if (area <= 1000) {
                valid_areas.insert(area);
            }
        }
    }

    // 判定
    int incorrect = 0;
    for (int i = 0; i < N; ++i) {
        if (valid_areas.find(S[i]) == valid_areas.end()) {
            incorrect++;
        }
    }

    cout << incorrect << endl;
    return 0;
}
