// BY LARA 1424
// https://codeforces.com/profile/DarkoLaraSlowed
// https://github.com/KaarLarax
// https://www.youtube.com/@KaarLarax

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
constexpr int MxN = 1e6 + 5;
constexpr array<int, 4> dx{1, 0, -1, 0};
constexpr array<int, 4> dy{0, 1, 0, -1};
bool verificar(string& str, char c) {
    for (const char& i : str) {
        if (i != c) {
            return false;
        }
    }
    return true;
}
int divisors(const string& str, const char& c) {
    int ans = -1;
    for (int i = 1; i <= sz(str); ++i) {
        bool band = true;
        for (int j = i; j <= sz(str); j += i) {
            if (c != str[j - 1]) {
                band = false;
            }
        }
        if (band) {
            ans = i;
            return ans;
        }
    }
    return ans;
}
// Main funtion
int main() {
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        int n;
        char a;
        string exist;
        cin >> n >> a >> exist;
        int posible = divisors(exist, a);
        if (verificar(exist, a)) {
            cout << 0 << edl;
        } else if (posible != -1) {
            cout << 1 << edl;
            cout << posible << edl;
        } else {
            cout << 2 << edl;
            cout << n - 1 << ' ' << n << edl;
        }
    }
    return 0;
}