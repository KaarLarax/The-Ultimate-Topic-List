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

ll bs(const int& n, const vector<ii>& arr) {
    auto good = [&](ll m) {
        for (int i = 0; i < n; ++i) {
            ll diferencia = arr[i].se - arr[i].fi;
            if (m < arr[i].fi) {
                return false;
            }
            m += diferencia;
            if (m < 0) {
                return false;
            }
        }
        return true;
    };
    ll l = 0, r = LLINF, m;
    while(l <= r) {
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
    vector<ii> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].fi >> arr[i].se;
    }
    sort(arr.begin(), arr.end(), [](auto &a, auto &b){
        ll dA = ll(a.second) - a.first;
        ll dB = ll(b.second) - b.first;
        if ((dA >= 0) != (dB >= 0))
            return dA >= 0;
        if (dA >= 0)
            return a.first < b.first;
        return a.second > b.second;
    });
    cout << bs(n, arr) << edl;
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