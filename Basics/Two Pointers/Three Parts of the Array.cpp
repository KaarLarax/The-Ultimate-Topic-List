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
    int n;
    cin >> n;
    vll arr(n + 1, 0), prefix(n + 1, 0), postfix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix[i] = arr[i] + prefix[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        postfix[i] = arr[i] + (i == n ? 0 : postfix[i + 1]);
    }
    int l = 1, r = n;
    ll ans = 0;
    while (l < r) {
        if (postfix[r] == prefix[l]) {
            ans = prefix[l];
            r--;
            l++;
        } else if (prefix[l] < postfix[r]) {
            l++;
        } else {
            r--;
        }
    }
    cout << ans << endl;
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