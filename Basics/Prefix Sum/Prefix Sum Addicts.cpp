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
constexpr int MxN = 1e5 + 5;
constexpr array<int, 4> dx{1, 0, -1, 0};
constexpr array<int, 4> dy{0, 1, 0, -1};
ll prefix[MxN], noprefix[MxN];
// Main funtion
int main() {
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        for (int i = n - (m - 1); i <= n; ++i) {
            cin >> prefix[i];
        }
        for (int i = n - (m - 1); i <= n; ++i) {
            noprefix[i] = prefix[i] - prefix[i - 1];
        }
        bool band = false;
        ll div = n - (m - 1);
        ll cantidad = noprefix[n - (m - 1)];
        ll number = cantidad / div;
        ll sobrante = cantidad % div;
        ll extra = sobrante / abs(sobrante);
        for (int i = 1; i <= n - (m - 1); ++i) {
            noprefix[i] = number;
        }
        for (int i = div - (abs(sobrante) - 1); i <= div; ++i) {
            noprefix[i] += extra;
        }
        sort(noprefix + 1, noprefix + (n - (m - 2)));
        for (int i = 2; i <= n; ++i) {
            if (noprefix[i] < noprefix[i - 1]) {
                band = true;
            }
        }
        if (band) {
            cout << "No" << edl;
        } else {
            cout << "Yes" << edl;
        }
        for (int i = 1; i <= n; ++i) {
            prefix[i] = noprefix[i] = 0;
        }
    }
    return 0;
}