#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q_cnt;
    cin >> n >> q_cnt;

    vector<int> qt(q_cnt);
    vector<int> qp(q_cnt);
    vector<string> qs(q_cnt);

    for (int i = 0; i < q_cnt; ++i) {
        cin >> qt[i] >> qp[i];
        if (qt[i] == 2) {
            cin >> qs[i];
        }
    }

    vector<int> bs; 
    vector<const string*> ss; 
    bs.reserve(n + 1 + q_cnt);
    ss.reserve(n + 1 + q_cnt);
    
    vector<int> p(n + 1);
    for (int i = 0; i <= n; ++i) {
        bs.push_back(-1);
        ss.push_back(nullptr);
        p[i] = i;
    }

    for (int i = 0; i < q_cnt; ++i) {
        if (qt[i] == 1) {
            p[qp[i]] = p[0];
        } else if (qt[i] == 2) {
            int base = p[qp[i]];
            bs.push_back(base);
            ss.push_back(&qs[i]);
            p[qp[i]] = bs.size() - 1;
        } else {
            p[0] = p[qp[i]];
        }
    }

    vector<const string*> res;
    int cur = p[0];
    while (cur != -1) {
        if (ss[cur] != nullptr) {
            res.push_back(ss[cur]);
        }
        cur = bs[cur];
    }

    reverse(res.begin(), res.end());

    for (const auto* s_ptr : res) {
        cout << *s_ptr;
    }
    cout << endl;

    return 0;
}