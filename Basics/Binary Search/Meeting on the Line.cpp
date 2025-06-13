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

int arr[MxN], d[MxN];

double bs(const int& n) {
    auto good = [&](const double& t) {
        double l = -DBL_MAX, r = DBL_MAX;
        for (int i = 0; i < n; ++i) {
            l = max(l, double(arr[i]) - (t - double(d[i])));
            r = min(r, double(arr[i]) + (t - double(d[i])));
        }
        return make_pair(l <= r, l + (r - l) / 2.00);
    };
    double l = 0, r = 1e9, m, ans;
    for (int i = 0; i < 100; ++i) {
        m = l + (r - l) / 2.0;
        auto temp = good(m);
        if (good(m).fi) {
            r = m;
            ans = temp.se;
        } else {
            l = m;
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    cout << fixed << setprecision(10) << bs(n) << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    int q = 1;
    cin >> q;
    while (q--) solve();
    return 0;
}
// By KaarLarax