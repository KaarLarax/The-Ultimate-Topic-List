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

bool good(int n, int a, int b, int t) {
    int ans = 0;
    if (a > b) {
        swap(a, b);
    }
    t -= a;
    ans++;
    if (t < 0) {
        return false;
    }
    int x = t / b, y = t / a;
    ans += x + y;
    return ans >= n;
}

int binarySearch(int n, int a, int b) {
    int l = 1, r = n * max(a, b), m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (good(n, a, b, m)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return l;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    cout << binarySearch(n, a, b) << edl;
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