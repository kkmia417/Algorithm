#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<int> cuts = {0};
    int angle = 0;

    for (int i = 0; i < N; ++i) {
        angle = (angle + A[i]) % 360;
        cuts.push_back(angle);
    }

    sort(cuts.begin(), cuts.end());

    int max_diff = 0;
    for (int i = 1; i < cuts.size(); ++i) {
        max_diff = max(max_diff, cuts[i] - cuts[i - 1]);
    }

    max_diff = max(max_diff, 360 - cuts.back());

    cout << max_diff << endl;

    return 0;
}
