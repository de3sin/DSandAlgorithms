#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

int n, q,
    a[maxn], lg[maxn], mn[maxn][20];

void preCompute() {
    // Updating the basis for Sparse Table
    for(int i=1; i<=n; ++i)
        mn[i][0] = a[i-1];
    
    // Update the Sparse Table
    for(int j=1; (1 << j)<=n; ++j)
        for(int i=1; i+(1 << j)-1<=n; ++i)
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j-1))][j-1]);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> q;

    for(int i=0; i<n; ++i)
        cin >> a[i];
    
    // Pre Computing the maximum power of 2 which is less than i
    lg[1] = 0;
    for(int i=2; i<=n; ++i)
        lg[i] = lg[i/2] + 1;

    preCompute();

    while(q--) {
        int l, r;
        cin >> l >> r;

        // Output the minimum of pre-computed parts
        // by dividing the interval to lg(i)
        // lg(i)'s maximum power of 2 fit inside i
        int sz = r - l + 1;
        cout << min(mn[l][lg[sz]], mn[r - (1 << lg[sz]) + 1][lg[sz]]) << '\n';
    }

    return 0;
}
