#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 3e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    set<ll> st;
    for (ll i = 2; i * i <= n; i++) {
        st.insert(i);
    }
    while (!st.empty()) {
        auto it = st.begin();
        ll val = *it;
        st.erase(val);
        for (ll j = val * val; j <= n; j *= val) {
            ans++;
            st.erase(j);
        }
    }
    ans = n - ans;
    cout << ans << endl;
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