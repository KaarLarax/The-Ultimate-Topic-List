// By Kaarlarax
// codeforces/Kaarlarax
// github/KaarLarax
// youtubeKaarLarax

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<long long>;
using vull = vector<ull>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vii = vector<pii>;
using vvi = vector<vi>;
using vvll = vector<vll>;

#define mp make_pair
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr int64_t LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr array<int, 4> dx{1, 0, -1, 0};
constexpr array<int, 4> dy{0, 1, 0, -1};

ll prefix[MxN];

// Main funtion
int main() {
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> prefix[i];
            prefix[i] += prefix[i - 1];
        }
        while (k--) {
            int l, r, m;
            cin >> l >> r >> m;
            ll range = prefix[r] - prefix[l - 1];
            ll ans = prefix[n] - range + (r - (l - 1)) * m;
            cout << (ans & 1? "YES": "NO") << edl;
        }
        for (int i = 1; i <= n; ++i) {
            prefix[i] = 0;
        }
    }
    return 0;
}