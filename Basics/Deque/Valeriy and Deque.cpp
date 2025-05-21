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
    int m, q;
    cin >> m >> q;
    int maxvalue = -INF;
    int maxindex = -1;
    deque<int> dq;
    for (int i = 1; i <= m; ++i) {
        int aux;
        cin >> aux;
        if (aux > maxvalue) {
            maxvalue = aux;
            maxindex = i;
        }
        dq.push_back(aux);
    }
    vector<pair<int, int>> ans1(maxindex), ans2(m);
    for (int i = 1; i < maxindex; ++i) {
        int temp = dq.front();
        dq.pop_front();
        ans1[i] = {temp, dq.front()};
        if (temp > dq.front()) {
            dq.push_back(dq.front());
            dq.pop_front();
            dq.push_front(temp);
        } else {
            dq.push_back(temp);
        }
    }
    for (int i = 1; i < m; ++i) {
        int temp = dq.front();
        dq.pop_front();
        ans2[i] = {temp, dq.front()};
        if (temp > dq.front()) {
            dq.push_back(dq.front());
            dq.pop_front();
            dq.push_front(temp);
        } else {
            dq.push_back(temp);
        }
    }
    while (q--) {
        ll n;
        cin >> n;
        if (n < maxindex) {
            cout << ans1[n].fi << ' ' << ans1[n].se << edl;
        } else {
            ll aux = (n - (maxindex - 1)) % (m - 1);
            if (aux == 0) {
                aux = (m - 1);
            }
            cout << ans2[aux].fi << " " << ans2[aux].se << edl;
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