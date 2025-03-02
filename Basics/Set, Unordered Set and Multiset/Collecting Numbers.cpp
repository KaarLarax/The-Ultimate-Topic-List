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
    set<pair<int, int>> s;
    int n, aux, contador = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        s.emplace(aux, i);
    }
    pair<int, int> anterior = {0, -1};
    for (int i = 1; i <= n; ++i) {
        auto it = s.lower_bound({i, -1});
        if (it-> second < anterior.second) {
            contador++;
        }
        anterior = *it;
    }
    cout << contador << edl;
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