/*By Kaarlarax
 *codeforces/Kaarlarax
 *github/KaarLarax
 *youtube/KaarLarax
*/

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

// Main funtion
int main() {
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vii notis;
    vi aps(n + 1);
    vi apsr(n + 1);
    int total = 0;
    int vistas = 0;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            notis.pb(b, 1);
            aps[b]++;
            total++;
        } else if (a == 2) {
            total -= aps[b];
            apsr[b] += aps[b];
            aps[b] = 0;
        } else {
            for (; vistas < b; vistas++) {
                if (apsr[notis[vistas].first] > 0) {
                    apsr[notis[vistas].first]--;
                    notis[vistas].se = false;
                } else if (notis[vistas].se) {
                    notis[vistas].se = 0;
                    aps[notis[vistas].fi]--;
                    total--;
                }
            }
        }
        cout << total << edl;
    }
    return 0;
}