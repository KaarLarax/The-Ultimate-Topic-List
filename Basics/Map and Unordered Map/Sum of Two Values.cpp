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
constexpr int MxN = 3e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    unordered_map<ll, int, custom_hash> mp, mp2;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int aux;
        cin >> aux;
        if (mp.find(aux) == mp.end()) {
            mp[aux] = i;
        } else {
            mp2[aux] = i;
        }
    }
    for (auto p = mp.begin(); p != mp.end(); ++p) {
        auto q = mp.find(m - (*p).fi);
        auto q2 = mp2.find(m - (*p).fi);
        if (q != mp.end() && q != p) {
            cout << (*p).se << ' ' << q->se << edl;
            return;
        } else if (mp2.find(m - (*p).fi) != mp2.end()) {
            cout << (*p).se << ' ' << q2->se << edl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << edl;
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