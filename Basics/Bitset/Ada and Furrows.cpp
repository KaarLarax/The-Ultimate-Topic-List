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

bitset<MxN> ans[MxN];

void solve() {
    int q;
    cin >> q;
    while (q--) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if (c == '+') {
            ans[x].set(y);
        } else if (c == '-') {
            ans[x].reset(y);
        } else if (c == 'v') {
            cout << (ans[x] | ans[y]).count() << edl;
        } else if (c == '^') {
            cout << (ans[x] & ans[y]).count() << edl;
        } else if (c == '!') {
            cout << (ans[x] ^ ans[y]).count() << edl;
        } else {
            cout << (ans[x] ^ (ans[x] & ans[y])).count() << edl;
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