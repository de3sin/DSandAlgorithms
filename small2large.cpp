#include <bits/stdc++.h>

using namespace std;

template <typename T>
inline void dbg(const char* name, const T& value) {
    cerr << name << " = " << value << '\n';
}

int n, m;
set<int> a, b;

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    freopen("test1.txt", "r", stdin);

    cin >> n >> m;
    for(int i=0; i<n; ++i) {
        int x; cin >> x;
        a.insert(x);
    }

    for(int j=0; j<m; ++j) {
        int x; cin >> x;
        b.insert(x);
    }

    if(n < m)
        swap(a, b);

    for(auto &x : b)
        a.insert(x);

    for(auto &x : a)
        cout << x << ' ';

    cout << '\n';
    return 0;
}
