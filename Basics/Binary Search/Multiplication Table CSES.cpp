// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

#define sz(x) int((x).size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr long long LLINF = 1e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 1e6 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll bs(const int& n, const ll& t) {
    auto good = [&](const ll k) {
        ll ans = 0LL;
        for (int i = 1; i <= n; ++i) {
            if (i > k) {
                continue;
            }
            if (1LL * n * i >= k) {
                ans += k / i;
            } else {
                ans += n;
            }
        }
        return ans >= (ll) t;
    };
    ll l = 1, r = 1LL * n * n, m;
    while (l <= r) {
        m = l + (r - l) / 2LL;
        if (good(m)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return l;
}

void solve() {
    int n;
    cin >> n;
    cout << bs(n, (1LL * n * n) / 2LL + 1LL) << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q = 1;
    // cin >> q;
    while (q--) solve();
    return 0;
}
// By KaarLarax
