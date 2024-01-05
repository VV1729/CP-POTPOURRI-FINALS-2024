#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

struct point {
	int x, y;
	point(int _x, int _y) : x(_x), y(_y) {}

	point operator-(point const& other) const {
		return point(x - other.x, y - other.y);
	}

	point& operator/=(int num) {
		x /= num;
		y /= num;
		return *this;
	}

	bool operator<(point const& other) const {
		return x < other.x || (x == other.x && y < other.y);
	}
};
int k;
void solve() {
	int n;
	cin >> n;
	vector<vector<point>> polys;
	vector<point> vecs;
	vector<int> borders;
	borders.push_back(0);
	for (int i = 0; i < n; ++i) {
		
		cin >> k;
		borders.push_back(borders.back() + k);
		polys.push_back({});
		for (int j = 0; j < k; ++j) {
			int x, y;
			cin >> x >> y;
			polys.back().push_back(point(x, y));
		}

		for (int j = 0; j < k; ++j) {
			int next = (j + 1) % k;
			point v = polys[i][next] - polys[i][j];
			int tmp = __gcd(abs(v.x), abs(v.y));
			v /= tmp;
			vecs.push_back(v);
		}
	}

	vector<int> arr;
	map<point, int> inds;
	for (auto v : vecs) {
		if (!inds.count(v)) {
			int tmp = szof(inds);
			inds[v] = tmp;
		}
		arr.push_back(inds[v]);
	}

	vector<int> next(szof(vecs));
	vector<int> last(szof(inds), INF);
	for (int i = szof(vecs) - 1; i >= 0; --i) {
		next[i] = last[arr[i]];
		last[arr[i]] = i;
	}


	vector<vector<pii>> here(szof(vecs));
	int q=1;
	vector<int> ans(q);
	for (int i = 0; i < 1; ++i) {
		int l, r;
		l=1;
		r=k;
		--l;
		l = borders[l];
		r = borders[r];
		here[l].push_back({r, i});
	}

	int bpv = 1;
	while (bpv < szof(vecs)) {
		bpv *= 2;
	}

	vector<int> segtree(bpv * 2);

	function<void(int, int)> segtree_set = [&](int pos, int val) {
		pos += bpv;
		segtree[pos] = val;
		pos /= 2;
		while (pos) {
			segtree[pos] = segtree[pos * 2] + segtree[pos * 2 + 1];
			pos /= 2;
		}
	};

	function<int(int, int, int, int, int)> segtree_get = [&](int v, int vl, int vr, int l, int r) {
		if (vr <= l || r <= vl) {
			return 0;
		}
		if (l <= vl && vr <= r) {
			return segtree[v];
		}
		int vm = (vl + vr) / 2;
		return segtree_get(v * 2, vl, vm, l, r) + segtree_get(v * 2 + 1, vm, vr, l, r);
	};

	for (int i = 0; i < szof(inds); ++i) {
		segtree_set(last[i], 1);
	}

	for (int i = 0; i < szof(vecs); ++i) {
		for (auto p : here[i]) {
			ans[p.ss] = segtree_get(1, 0, bpv, i, p.ff);
		}
		segtree_set(i, 0);
		if (next[i] != INF) {
			segtree_set(next[i], 1);
		}
	}

	for (int num : ans) {
		cout << num << "\n";
	}
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
