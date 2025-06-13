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

bool good(const vi& arr, ll target, ll cows) {
    ll mini = INT64_MAX;
    ll actual = 0;
    for (int i = 0; i < cows - 1; ++i) {
        auto temp = upper_bound(arr.begin() + actual, arr.end(), arr[actual] + (target - 1));
        if (temp == arr.end()) return false;
        mini = min(mini, *temp - arr[actual]);
        actual = temp - arr.begin();
    }
    return mini >= target;
}

ll bs(const vi& arr, ll cows) {
    ll l = 1, r = arr[sz(arr) - 1], m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (good(arr, m, cows)) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return r;
}

void solve() {
    int n, c;
    cin >> n >> c;
    vi stalls(n);
    for (int i = 0; i < n; ++i) {
        cin >> stalls[i];
    }
    cout << bs(stalls, c) << edl;
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