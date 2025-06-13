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

int minNumber(const vi& arr) {
    int l = 0, r = sz(arr) - 1, m;
    while (l < r) {
        m = l + (r - l) / 2;
        if (arr[m] > arr[r]) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

void solve() {
    vi arr = {4, 5, 6, 7, 0, 1, 2, 3, 8, 9};
    cout << minNumber(arr) << edl;
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