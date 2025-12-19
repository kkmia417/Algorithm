#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        G[v].push_back(u);
    }

    int Q;
    cin >> Q;

    vector<bool> vis(N + 1, false);
    queue<int> q;

    while (Q--) {
        int t, v;
        cin >> t >> v;
        if (t == 1) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int nxt : G[cur]) {
                    if (!vis[nxt]) {
                        vis[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        } else {
            cout << (vis[v] ? "Yes" : "No") << "\n";
        }
    }

    return 0;
}