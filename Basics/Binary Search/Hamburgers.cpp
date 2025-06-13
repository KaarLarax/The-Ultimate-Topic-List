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
constexpr int MxN = 1e6 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool good(ll coins, vi ne, ll m, vi cost, vi kit) {
    ll costo = 0;
    for (int i = 0; i < 3; ++i) {
        ll nece = ne[i] * m;
        if (nece > kit[i]) {
            costo += (nece - kit[i]) * cost[i];
        }
        if (costo > coins) {
            return false;
        }
    }
    return coins >= costo;
}

void solve() {
    vi ne(3, 0);
    string recipe;
    cin >> recipe;
    for (char c : recipe) {
        if (c == 'B') {
            ne[0]++;
        } else if (c == 'S') {
            ne[1]++;
        } else if (c == 'C') {
            ne[2]++;
        }
    }
    vi kit(3);
    for (int i = 0; i < 3; i++) {
        cin >> kit[i];
    }
    vi prices(3);
    for (int i = 0; i < 3; i++) {
        cin >> prices[i];
    }
    ll coins;
    cin >> coins;
    ll posibles = LLINF;
    for (int i = 0; i < 3; ++i) {
        if (ne[i] != 0) {
            posibles = min(kit[i] / ne[i], posibles);
        }
    }
    for (int i = 0; i < 3; ++i) {
        kit[i] -= posibles * ne[i];
    }
    ll l = 0, r = 1e13, m;
    ll ans = 0;
    while (l <= r) {
        m = l + (r - l) / 2ll;
        if (good(coins, ne, m, prices, kit)) {
            l = m + 1;
            ans = m;
        } else {
            r = m - 1;
        }
    }
    cout << posibles + ans << edl;
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