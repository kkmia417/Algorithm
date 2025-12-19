#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> points(N);

    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double maxDist = 0.0;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            double dx = points[i].first - points[j].first;
            double dy = points[i].second - points[j].second;
            double dist = sqrt(dx * dx + dy * dy);
            maxDist = max(maxDist, dist);
        }
    }

    cout << fixed << setprecision(12) << maxDist << endl;
    return 0;
}
