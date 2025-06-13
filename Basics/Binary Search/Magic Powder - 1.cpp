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

ll bs(const ll& n, const ll& k, const vi& need, const vi& has) {
    auto good = [&](const ll m) {
        ll t = 0;
        for (int i = 0; i < n; i++) {
            if (has[i] / need[i] < m) {
                t += need[i] * m - has[i];
            }
            if (t > k) {
                return false;
            }
        }
        return true;
    };
    ll l = 0, r = INF, m;
    while (l <= r) {
        m = midpoint(l, r);
        if (good(m)) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return r;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vi need(n), has(n);
    for (int i = 0; i < n; i++) {
        cin >> need[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> has[i];
    }
    cout << bs(n, k, need, has) << edl;
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