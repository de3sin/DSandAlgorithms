#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;

int n, q;
vector<int> par(maxn),
            sz(maxn, 1);

int find_par(int v) {
    if (par[v] == v)
        return v;

    return par[v] = find_par(par[v]);
}

void merge(int u, int v) {
    u = find_par(u);
    v = find_par(v);
    if (u != v)
        par[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> q;

    for(int v=1; v<=n; ++v)
        par[v] = v;

    while (q--) {
        int x, y, op;
        cin >> x >> y >> op;
        if (op == 1)
            cout << (find_par(x) == find_par(y) ? "YES" : "NO") << endl;
        else
            merge(x, y);
    }

    return 0;
}
