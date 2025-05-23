// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr ll LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 1e6 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n;
    cin >> n;
    vll arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    vi first(7, -1), last(7, -1);
    ll prefix = 0;
    first[0] = 0;
    last[0] = 0;

    for (int i = 1; i <= n; ++i) {
        prefix = (prefix + arr[i]) % 7;
        if (first[prefix] == -1) first[prefix] = i;
        last[prefix] = i;
    }

    ll ans = 0;
    for (int r = 0; r < 7; ++r) {
        if (first[r] != -1) {
            ans = max(ans, ll(last[r] - first[r]));
        }
    }

    cout << ans << edl;
}

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int q = 1;
    // cin >> q;
    while (q--) solve();
    return 0;
}
// By KaarLarax