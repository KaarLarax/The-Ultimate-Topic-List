#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool good(vi& d, vi& v, double m) {
    double mini = -DBL_MAX, maxi = DBL_MAX;
    for (int i = 0; i < sz(d); ++i) {
        mini = max(mini, d[i] - v[i] * m);
        maxi = min(maxi, d[i] + v[i] * m);
    }
    return mini <= maxi;
}
double bs(vi d, vi v) {
    double l = 1e-9, r = 1e9, m;
    for (int i = 0; i < 100; ++i) {
        m = l + (r - l) / 2.00;
        if (good(d, v, m)) {
            r = m;
        } else {
            l = m;
        }
    }
    return l + (r - l) / 2.00;
}

void solve() {
    int n;
    cin >> n;
    vi d(n), v(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i] >> v[i];
    }
    cout << setprecision(10) << bs(d, v) << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
// By KaarLarax