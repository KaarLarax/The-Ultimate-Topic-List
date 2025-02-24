// BY LARA 1424
// https://codeforces.com/profile/DarkoLaraSlowed
// https://github.com/KaarLarax
// https://www.youtube.com/@KaarLarax

#include <bits/stdc++.h>

// Namespaces
using namespace std;

// Typedefs
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vii = vector<pii>;
using vvi = vector<vi>;
using vvll = vector<vll>;

// Macros
#define debug(x) cerr << #x << " = " << x << '\n'
#define mp make_pair
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

// Constants
constexpr int64_t LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr array<int, 4> dx{1, 0, -1, 0};
constexpr array<int, 4> dy{0, 1, 0, -1};

// Main funtion
int32_t main() {
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q;
    cin >> q;
    int elements[q];
    for (int i = 0; i < q; ++i) {
        cin >> elements[i];
    }
    for (int mask = 0; mask < (1 << q); ++mask) {
        int suma = 0;
        for (int i = 0; i < q; ++i) {
            if (mask & 1 << i) {
                suma += elements[i];
            } else {
                suma -= elements[i];
            }
            suma %= 360;
        }
        if (suma == 0) {
            cout << "YES" << edl;
            return 0;
        }
    }
    cout << "NO" << edl;
    return 0;
}