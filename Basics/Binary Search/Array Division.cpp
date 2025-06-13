#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

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

bool good(const vi &arr, const int &k, const ll &m) {
    ll sum = 0;
    int segment = 1;
    for (int i = 0; i < sz(arr); ++i) {
        if (sum + arr[i] <= m) {
            sum += arr[i];
        } else if (arr[i] <= m) {
            sum = arr[i];
            segment++;
        } else {
            return false;
        }
    }
    return segment <= k;
}

ll bs(const vi &arr, const int &k) {
    ll l = 1, r = INT64_MAX, m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (good(arr, k, m)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return l;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << bs(arr, k) << edl;
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