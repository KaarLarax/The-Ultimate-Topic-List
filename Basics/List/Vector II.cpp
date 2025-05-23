#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e4 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

list<int> ans[10001];
void solve() {
    int n, q;
    cin >> n >> q;

    while (q--) {
        int val;
        cin >> n >> val;
        if (n == 0) {
            int x;
            cin >> x;
            ans[val].emplace_back(x);
        } else if (n == 1) {
            for (auto it = ans[val].begin(); it != ans[val].end(); it++) {
                auto item = it;
                if (++item == ans[val].end()) {
                    cout << *it;
                } else {
                    cout << *it << ' ';
                }
            }
            cout << edl;
        } else if (!ans[val].empty()) {
            ans[val].clear();
        }
    }
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