// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

#define sz(x) int((x).size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 1e6 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ull bs(const ull& n, const ull& k) {
    auto good = [&](const ull x) {
        ull ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (i > x) {
                continue;
            }

            if (i * n >= x) {
                ans += x / i;
            } else {
                ans += n;
            }
        }
        return ans;
    };
    ull l = 1, r = 1ULL * n * n, m, ans = 1;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (good(m) >= k) {
            r = m - 1;
            ans = m;
        } else {
            l = m + 1;
        }
    }
    return ans;
}

void solve() {
    ull n, k;
    cin >> n >> k;
    cout << bs(n, k) << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q = 1;
    // cin >> q;
    while (q--) solve();
    return 0;
}
// By KaarLarax
