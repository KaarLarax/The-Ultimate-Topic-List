// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vii = vector<ii>;

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
    int n, x;
    cin >> n >> x;
    vii arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr.at(i).fi;
        arr.at(i).se = i + 1;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        int l = 0, r = n - 1;
        ll target = x * 1ll - arr[i].fi;
        while (l < r) {
            ll temp = 1ll * arr[l].fi + arr[r].fi;
            if (target <= 1) {
                break;
            } else if (temp > target) {
                r--;
            } else if (temp < target) {
                l++;
            } else if (l != i && r != i) {
                cout << arr[i].se << ' ' << arr[l].se << ' ' << arr[r].se << edl;
                return;
            } else {
                break;
            }
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
    return 0;
}
// By KaarLarax