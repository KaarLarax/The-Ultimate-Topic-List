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
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    deque<int> soldier[2];
    vector<pair<deque<int>, deque<int>>> posibles;
    int n;
    cin >> n;
    for (int i = 0; i < 2; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int aux;
            cin >> aux;
            soldier[i].push_back(aux);
        }
    }
    auto it = posibles.end();
    int contador = 0;
    do {
        posibles.pb(soldier[0], soldier[1]);
        if (soldier[0].empty()) {
            cout << contador << " " << 2 << edl;
            return;
        } else if (soldier[1].empty()) {
            cout << contador << " " << 1 << edl;
            return;
        }
        int winner = soldier[0].front() > soldier[1].front() ? 0 : 1;
        int loser = winner ^ 1;
        int aux = soldier[winner].front();
        soldier[winner].pop_front();
        soldier[winner].push_back(soldier[loser].front());
        soldier[loser].pop_front();
        soldier[winner].push_back(aux);
        contador++;
        it = find_if(posibles.begin(), posibles.end(), [&](const pair<deque<int>, deque<int>> &p) {
            return (p.first == soldier[0] && p.second == soldier[1]) ||
                   (p.first == soldier[1] && p.second == soldier[0]);
        });

    } while (it == posibles.end());
    cout << -1 << edl;
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