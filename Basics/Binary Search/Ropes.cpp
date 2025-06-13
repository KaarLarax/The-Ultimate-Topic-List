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
constexpr int MxN = 1e6 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool good(const vi& arr, const double& x, const ll& k) {
    ll s = 0;
    for (const auto& i: arr) {
        s += floor(i / x);
    }
    return s >= k;
}

double binarySearch(const vi& arr, const ll& k) {
    double l = 0.00, r = 1e8, m;
    for (int i = 0; i < 100; ++i) {
        m = l + (r - l) / 2;
        if (good(arr, m, k)) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi arr(n);
    for (auto& item: arr) {
        cin >> item;
    }
    cout << setprecision(20) << binarySearch(arr, k) << edl;
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