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

bool square(const ull& m, const ull& a, const ull& b, const ull& n) {
    return (m / a) * (m / b) >= n;
}

ull binarySearch(const ull& a, const ull& b, const ull& n) {
    ull l = 0, r = 1, m;
    while (!square(r, a, b, n)) r <<= 1;

    while (l <= r) {
        m = l + (r - l) / 2;
        if (square(m, a, b, n)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return l;
}

void solve() {
    ull a, b, n;
    cin >> a >> b >>n;
    cout << binarySearch(a, b, n) << edl;
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