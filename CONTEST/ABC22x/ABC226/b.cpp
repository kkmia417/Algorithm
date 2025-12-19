#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;

    set<vector<int>> unique_sequences;

    // setは重複ゆるさない

    for (int i = 0; i < N; ++i) {
        int L;
        cin >> L;
        vector<int> sequence(L);
        for (int j = 0; j < L; ++j) {
            cin >> sequence[j];
        }
        unique_sequences.insert(sequence);
    }

    cout << unique_sequences.size() << endl;
    return 0;
}
