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

vi arr;

int bs(const int& k) {
    int n = sz(arr);
    auto good = [&](const int& x) {
        ll ans = 0;
        for (int i = (n - 1) / 2; i < n; ++i) {
            ans += 1LL * max(0, x - arr[i]);
        }
        return ans;
    };
    int l = 0, r = INF, m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (good(m) > k) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return r;
}

void solve() {
    int n, k;
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    cout << bs(k) << edl;
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
