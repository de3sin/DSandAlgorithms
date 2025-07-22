#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 3;

/* --------- Containers Deffined HERE! ----------- */

int T, Ts, q;

vector<int> adj[maxn],
            a,
            lg(maxn);
int         mn[maxn][20];

vector<bool> mark(maxn);

/* ----------------------------------------------- */

void dfs(int v, int d = 0) {
    mark[v] = 1;
    if (first[v] == -1)
        first[v] = a.size();
    a.emplace_back(v);       // Add the vertices to RMQ array
    depth.emplace_back(d);   // in order of occurring in DFS

    for (int &u : adj[v])
        if (!mark[u]) {
            dfs(u, d + 1);
            a.emplace_back(v);
            depth.emplace_back(d);
        }
}

void build_sparse_table(int n) {
    // Base cases update
    int n = depth.size();
    for (int i = 1; i <= n; ++i)
        mn[i][0] = a[i - 1];

    // Spare table update
    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j-1))][j - 1]);
}

void log_preCompute(int n) {
    // Calculate the max power of 2 less-equal than n
    lg[1] = 0;
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i / 2] + 1;
}

int lca(int u, int v, int n) {
    auto pos = [](int x, vector<int> &a) -> int {
        for (int i = 1; i <= n; ++i)
            if (a[i] == x)
                return i;
    };

    dfs(0);

    build_sparse_table(n);

    log_preCompute(n);

    int l = pos[u];
    int r = pos[v];
    if (l > r) swap(l, r);

    int z = lg[r - l + 1];
    int x = mn[l][j];
    int y = mn[r - (1 << j) + 1][j];

    return (depth[x] < depth[y]) ? a[x] : a[y];
}

void input() {
    auto addEdge = []() -> void {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    };

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int m; cin >> m;
        for (int j = 1; j <= m; ++j)
            addEdge();
    }

    cout << "Case " << T - Ts << ": \n";

    cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        cout << lca(u, v, n) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> T; Ts = T;
    while (T--)
        input();

    return 0;
}
