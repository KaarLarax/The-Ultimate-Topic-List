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
    int n, q;
    cin >> n >> q;
    map<int, vi> arr;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        arr[aux].pb(i);
    }
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        if (arr.find(x) == arr.end()) {
            cout << 0 << edl;
            continue;
        }
        auto lo = lower_bound(arr[x].begin(), arr[x].end(), l) - arr[x].begin();
        auto hi = lower_bound(arr[x].begin(), arr[x].end(), r) - arr[x].begin();
        cout << hi - lo << edl;
    }
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