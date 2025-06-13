// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vi = vector<int>;

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


class Solution {
public:
    long long lcm(const long long& a, const long long& b) {
        return (a * b) / __gcd(a, b);
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        auto good = [&](const long long& x) {
            ll ans = 0;
            ans += x / a;
            ans += x / b;
            ans += x / c;
            ans -= x / (lcm(a, b));
            ans -= x / (lcm(a, c));
            ans -= x / (lcm(b, c));
            ans += x / (lcm(a, lcm(b, c)));
            return ans < n;
        };
        long long l = 1, r = 2e18, m;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (good(m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return int(l);
    }
};

void solve() {

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