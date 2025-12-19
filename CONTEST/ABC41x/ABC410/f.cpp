#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int find_root(int i, vector<int>& parent) {
    if (parent[i] == i) return i;
    return parent[i] = find_root(parent[i], parent);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> es(m + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> es[i].first >> es[i].second;
        adj[es[i].first].push_back(es[i].second);
        adj[es[i].second].push_back(es[i].first);
    }
    
    int q_cnt;
    cin >> q_cnt;
    vector<int> qs(q_cnt);
    for (int i = 0; i < q_cnt; ++i) {
        cin >> qs[i];
    }
    
    vector<int> par(n + 1);
    iota(par.begin(), par.end(), 0);
    vector<int> sz(n + 1, 1);
    vector<vector<int>> mem(n + 1);
    for(int i = 1; i <= n; ++i) {
        mem[i].push_back(i);
    }
    
    long long current_edges = m;

    for (int x_idx : qs) {
        int u = es[x_idx].first;
        int v = es[x_idx].second;

        int root_u = find_root(u, par);
        int root_v = find_root(v, par);

        if (root_u != root_v) {
            if (sz[root_u] > sz[root_v]) {
                swap(root_u, root_v);
            }

            for (int node : mem[root_u]) {
                for (int neighbor : adj[node]) {
                    if (find_root(neighbor, par) == root_v) {
                        current_edges--;
                    }
                }
            }
            
            par[root_u] = root_v;
            sz[root_v] += sz[root_u];
            mem[root_v].insert(mem[root_v].end(), mem[root_u].begin(), mem[root_u].end());
            mem[root_u].clear();
        }
        
        cout << current_edges << "\n";
    }

    return 0;
}