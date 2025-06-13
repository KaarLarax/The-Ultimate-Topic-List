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

void solve() {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if (a == b) {
        cout << min(x, y) / a << edl;
        return;
    }
    if (a < b) {
        swap(a, b);
    }
    ll l = 0, r = 1e9 + 100;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        ll right = floorl((x - m * b) * 1.0l / (a - b));
        ll left = ceill((y - m * a) * 1.0l / (b - a));
        if (max(left, 0ll) <= min(right, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    int q = 1;
    cin >> q;
    while (q--) solve();
    return 0;
}
// By KaarLarax