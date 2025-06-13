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

bool good(vi& arr, int k, ll mid) {
    ll ans = 0;
    for (ll& i : arr) {
        ans += min(i, mid);
    }
    return ans >= mid * k;
}

ll bS(vi& arr, int k) {
    ll l = 0, r = (50ll * (INF * 1ll)) / k * 1ll, m;
    while (l <= r) {
        m = l + (r - l) / 2ll;
        if (good(arr, k, m)) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return r;
}

void solve() {
    int k, n;
    cin >> k >> n;
    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << bS(arr, k) << edl;
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