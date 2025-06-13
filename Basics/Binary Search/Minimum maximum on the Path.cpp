#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;

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

void solve() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<tuple<int,int,ll>> edges;
    edges.reserve(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    auto can = [&](ll maxW, vector<int>& parent) {
        vector<vector<int>> adj(n+1);
        for (auto& e : edges) {
            int u, v; ll w;
            tie(u, v, w) = e;
            if (w <= maxW) {
                adj[u].pb(v);
            }
        }
        vector<int> dist(n+1, INF);
        dist[1] = 0;
        parent.assign(n+1, -1);

        deque<int> q;
        q.push_back(1);

        while (!q.empty()) {
            int u = q.front(); q.pop_front();
            if (dist[u] == d) continue;
            for (int v : adj[u]) {
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push_back(v);
                }
            }
        }
        return dist[n] <= d;
    };

    ll lo = 0, hi = 1e9, best = -1;
    vector<int> finalParent;

    while (lo <= hi) {
        ll mid = (lo + hi) >> 1;
        vector<int> parent;
        if (can(mid, parent)) {
            best = mid;
            finalParent = move(parent);
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    if (best == -1) {
        cout << -1 << edl;
        return;
    }

    vector<int> path;
    for (int u = n; u != -1; u = finalParent[u]) {
        path.pb(u);
    }
    reverse(path.begin(), path.end());

    cout << sz(path) - 1 << edl;
    for (int u : path) {
        cout << u << ' ';
    }
    cout << edl;
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
