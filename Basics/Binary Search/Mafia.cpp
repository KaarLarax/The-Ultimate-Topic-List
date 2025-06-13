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

ll bs(const int& n, const vi& rounds) {
    auto good = [&](ll m) {
        ll posibles = 0;
        for (int i = 0; i < n; ++i) {
            if (m - rounds[i] < 0) {
                return false;
            }
            posibles += m - rounds[i];
            if (posibles >= m) {
                return true;
            }
        }
        return posibles >= m;
    };
    ll l = *max_element(rounds.begin(), rounds.end()), r = LLINF, m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (good(m)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return l;
}

void solve() {
   int n;
   cin >> n;
   vi rounds(n);
   for (int i = 0; i < n; i++) {
       cin >> rounds[i];
   }
   cout << bs(n, rounds) << edl;
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