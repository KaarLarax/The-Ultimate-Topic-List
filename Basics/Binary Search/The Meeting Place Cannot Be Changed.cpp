// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vi = vector<int>;
using ii = pair<int, int>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 1e6 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

double bs(const int& n, const vi& d, const vi& v) {
    auto good = [&](const double& t) {
        double l = 1e-9, r = 1e9;
        for (int i = 0; i < n; ++i) {
            l = max(1.00 * d[i] - 1.00 * t * v[i], l);
            r = min(1.00 * d[i] + 1.00 * t * v[i], r);
        }
        return l <= r;
    };
    double l = 1e-9, r = 1e9, m;
    for (int i = 0; i < 100; i++) {
        m = l + (r - l) / 2.00;
        if (good(m)) {
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
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << fixed << setprecision(10) << bs(n, d, v) << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    int q = 1;
    // cin >> q;
    while (q--) solve();
    return 0;
}
// By KaarLarax