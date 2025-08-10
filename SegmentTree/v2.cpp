/* In the name of Allah */
// Welcome to the Soldier Side!
// Where there's no one here, but me...
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
long long seg[N << 2];
int n, a[N];

void update(int l, int r, int x, int id = 1, int st = 0, int en = n) {
	if (r <= st || en <= l)
		return;
	if (l <= st && en <= r) {
		seg[id] += x;
		return;
	}

	int mid = st + en >> 1;
	update(l, r, x, id << 1, st, mid);
	update(l, r, x, id << 1 | 1, mid, en);
}

long long get(int p, int id = 1, int st = 0, int en = n) {
	if (en - st == 1)
		return seg[id];

	int mid = st + en >> 1;
	long long ans = seg[id];
	if (p < mid)
		ans += get(p, id << 1, st, mid);
	else
		ans += get(p, id << 1 | 1, mid, en);
	return ans;
}

void read_input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void solve() {
	// Queries:
	// - update(l, r, x)
	// - get(p)
}

int main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	read_input(), solve();
	return 0;
}
