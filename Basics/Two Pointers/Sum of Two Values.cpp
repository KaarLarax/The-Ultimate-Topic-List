#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
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
    int n;
    ll t;
    cin >> n >> t;
    vector<ii> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].fi;
        arr[i].se = i + 1;
    }
    sort(arr.begin(), arr.end());
    int l = 0, r = n - 1;
    while (l < r ) {
        ll temp = arr[l].fi + arr[r].fi;
        if (temp == t) {
            cout << arr[l].se << ' ' << arr[r].se << edl;
            return;
        } else if (temp < t) {
            l++;
        } else {
            r--;
        }
    }
    cout << "IMPOSSIBLE" << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    // vsCode; // solo vs code debugger
    return 0;
}
// By KaarLarax