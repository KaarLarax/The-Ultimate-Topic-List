// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vi = vector<int>;
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
        cin >> arr[i].fi;
        arr[i].se = i + 1;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll target = 1ll * x - arr[i].fi - arr[j].fi;
            int l = j + 1, r = n - 1;
            if (l >= n) {
                break;
            }
            while(l < r) {
                ll temp = 1ll * arr[l].fi + arr[r].fi;
                if (temp > target) {
                    r--;
                } else if (temp < target) {
                    l++;
                } else {
                    cout << arr[i].se << ' ' << arr[j].se << ' ' << arr[l].se << ' ' << arr[r].se << edl;
                    return;
                }
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
    while (q--) solve();
    return 0;
}
// By KaarLarax