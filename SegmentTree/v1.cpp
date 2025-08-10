/* In the name of Allah */
// Welcome to the Soldier Side!
// Where there's no one here, but me...
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
long long seg[N << 2];
int n, a[N];

void build(int id = 1, int st = 0, int en = n) {
	if (en - st == 1) {
		seg[id] = a[st];
		return;
	}

	int mid = st + en >> 1;
	build(id << 1, st, mid);
	build(id << 1 | 1, mid, en);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

void update(int p, int x, int id = 1, int st = 0, int en = n) {
	if (en - st == 1) {
		seg[id] = x;
		return;
	}

	int mid = st + en >> 1;
	update(p, x, id << 1, st, mid);
	update(p, x, id << 1 | 1, mid, en);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

long long get(int l, int r, int id = 1, int st = 0, int en = n) {
	if (r <= st || en <= l)
		return 0;
	if (l <= st && en <= r)
		return seg[id];

	int mid = st + en >> 1;
	return get(l, r, id << 1, st, mid) + get(l, r, id << 1 | 1, mid, en);
}

void read_input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void solve() {
	build();
	// Queries:
	// - update(p, x)
	// - get(l, r)
}

int main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	read_input(), solve();
	return 0;
}
