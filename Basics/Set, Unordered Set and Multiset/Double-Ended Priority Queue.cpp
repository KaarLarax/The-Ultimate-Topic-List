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
constexpr int MxN = 3e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n, m;
    multiset<int> ms;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int aux;
        cin >> aux;
        ms.insert(aux);
    }
    while (m--) {
        int o;
        cin >> o;
        if (o == 0) {
            int aux;
            cin >> aux;
            ms.insert(aux);
        } else if (o == 1) {
            cout << *ms.begin() << edl;
            ms.erase(ms.begin());
        } else {
            cout << *ms.rbegin() << edl;
            ms.erase(ms.find(*ms.rbegin()));
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