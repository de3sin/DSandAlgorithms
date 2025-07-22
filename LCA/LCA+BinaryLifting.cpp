#include <bits/stdc++.h>

using namespace std;

const int maxn = 1'000 + 1,
          loog = 11;

int n,
    par[maxn][loog],
    depth[maxn];
vector<int> child[maxn];

void dfs(int v, int p = 0) {
    par[v][0] = p;
    for (int i = 1; i < loog; ++i)
        par[v][i] = par[par[v][i - 1]][i - 1];

    for (int &u : child[v]) {
        if (u == p)
            continue;

        depth[u] = depth[v] + 1;
        dfs(u, v);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);

    while (depth[u] > depth[v])
        u = par[u][0];
    
    while (u != v) {
        u = par[u][0];
        v = par[v][0];
    }

    return u;
}

void input() {
    cin >> n;
    vector<bool> is_root(n + 1, 1);

    for (int i = 1; i <= n; ++i) {
        int m; cin >> m;
        while (m--) {
            int c; cin >> c;
            child[i].emplace_back(c);
            is_root[c] = 0;
        }
    }

    int root = 1;
    for (int i = 1; i <= n; ++i)
        if (is_root[i]) {
            root = i;
            break;
        }

    depth[root] = 0;
    dfs(root);

    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}

void clean() {
    n = 0;
    for (int i = 0; i < maxn; ++i) {
        child[i].clear();
        depth[i] = 0;
        for (int j = 0; j < loog; ++j)
            par[i][j] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T;
    cin >> T;
    int Ts = T;
    while (T--) {
        cout << "Case " << Ts - T << ":\n";
        input();
        clean();
    }

    return 0;
}
