#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    multimap<int, int> pasta;
    vector<int> A(N), B(M);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        pasta.insert({A[i], i}); 
    }

    for (int i = 0; i < M; ++i) {
        cin >> B[i];
        auto it = pasta.find(B[i]);
        if (it == pasta.end()) {
            cout << "No" << endl;
            return 0;
        } else {
            pasta.erase(it);
        }
    }

    cout << "Yes" << endl;
    return 0;
}
