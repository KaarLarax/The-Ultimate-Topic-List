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

ii prefix[MxN];
const string mv = "RULD";
void solve() {
    int x, y, fx1, fy1, n;
    string str;
    cin >> x >> y >> fx1 >> fy1 >> n >> str;
    for (int i = 0; i < n; i++) {
        int index = -1;
        for (int j = 0; j < 4; ++j) {
            if (mv[j] == str[i]) {
                index = j;
            }
            prefix[i + 1] = {prefix[i].first + dx[index], prefix[i].se + dy[index]};
        }

    }
    ll l = 0, r = LLINF, m, ans = -1;
    auto good = [&](const ll& m) {
        ll loop = m / n, days = m % n;
        ll x1 = x + prefix[days].fi + 1LL * prefix[n].fi * loop, y1 = y + prefix[days].se + 1LL * prefix[n].se * loop;
        ll dist = llabs(x1 - fx1) + llabs(y1 - fy1);
        return dist <= m;
    };
    while (l <= r) {
        m = l + (r - l) / 2;
        if (good(m)) {
            r = m - 1;
            ans = m;
        } else {
            l = m + 1;
        }
    }
    cout << ans << edl;
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