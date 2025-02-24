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
    ull t, sobrante = 0, cobinations = 0;
    cin >> t;
    while (sobrante != t) {
        cobinations++;
        sobrante = t % (int) pow(10, cobinations);
    }
    if (cobinations & 1ull) {
        cobinations++;
    }
    for (int i = 0; i < ( 1 << cobinations); ++i) {
        ull temp = 0;
        ull band4 = 0, band7 = 0;
        for (int j = 0; j < cobinations; ++j) {
            if (i & (1 << j)) {
                temp += 7ull * (ull) (pow(10, j));
                band7++;
            } else {
                temp += 4ull * (ull) (pow(10, j));
                band4++;
            }
        }
        if (temp >= t && band4 == band7 ) {
            cout << temp << edl;
            return 0;
        }
    }
    for (int i = 0; i < ( 1 << (cobinations + 2)); ++i) {
        ull temp = 0;
        ull band4 = 0, band7 = 0;
        for (int j = 0; j < cobinations + 2; ++j) {
            if (i & (1 << j)) {
                temp += 7ull * (ull) (pow(10, j));
                band7++;
            } else {
                temp += 4ull * (ull) (pow(10, j));
                band4++;
            }
        }
        if (temp >= t && band4 == band7 ) {
            cout << temp << edl;
            return 0;
        }
    }
    return 0;
}