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

ll binarySearch(const ll& k, const vi& arr) {
    ll l = 0, r = sz(arr) - 1, m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (arr[m] <= k) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    if (r == -1) {
        return arr[l];
    } else if (l == sz(arr)) {
        return arr[r];
    }
    return ((k - arr[r]) <= (arr[l] - k) ? arr[r] : arr[l]);
}

void solve() {
    vi arr = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    cout << binarySearch(5, arr) << edl;
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