#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; ++i) cin >> A[i];

    unordered_set<int> possible_sums;

    // bit全探索で全ての部分集合の和を求める
    for(int bit = 0; bit < (1 << n); ++bit) { //0 から 2^n - 1 までのすべての整数を走査
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            if(bit & (1 << i)) {
                sum += A[i];
            }
        }
        possible_sums.insert(sum);
    }

    int q;
    cin >> q;
    while(q--) {
        int m;
        cin >> m;
        if(possible_sums.count(m)) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
