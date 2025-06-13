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

int a[MxN], b[MxN];

void bs(const int& n, const int& k) {
    for (int i = 0; i < k; i++) {
        int l = 0, r = n - 1, m;
        while(l <= r) {
            m = l + (r - l) / 2;
            if (a[m] > b[i]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        cout << l << ' ';
    }
    cout << edl;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    bs(n, m);
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
