#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

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

double ps[MxN], nums[MxN], mps[MxN];
int mn_pos[MxN];
int n, d;

pair<bool, pair<int, int>> good(const double & x) {
    for (int i = 1; i <= n; ++i) {
        ps[i] = (nums[i] - x) + ps[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        if (ps[i] < mps[i-1]) {
            mps[i] = ps[i];
            mn_pos[i] = i;
        } else {
            mps[i] = mps[i-1];
            mn_pos[i] = mn_pos[i-1];
        }
    }
    for (int i = d; i <= n; ++i) {
        if (ps[i] - mps[i - d] >= 0) {
            return {true, {mn_pos[i - d] + 1, i}};
        }
    }
    return {false, {-1, -1}};
}

pair<int, int> bs() {
    int a = 1, b = d;
    double l = 0, r = 100, m;
    for (int i = 0; i < 100; i++) {
        m = l + (r - l) / 2.00;
        auto x = good(m);
        if (x.first) {
            l = m;
            a = x.se.fi;
            b = x.se.se;
        } else {
            r = m;
        }
    }
    return {a, b};
}

void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    auto ans = bs();
    cout << ans.fi << ' ' << ans.se << edl;
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
