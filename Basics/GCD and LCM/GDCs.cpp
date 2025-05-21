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

ll mcd(ll n, ll m) {
    ll remained;
    while (m != 0) {
        remained = m;
        m = n % m;
        n = remained;
    }
    return n;
}
ll mcm(ll n, ll m) { return m / mcd(n, m) * n; }
bool ans[101];
// Main funtion
int main() {
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll n;
    cin >> n;

    vll divisors(n);
    for (int i = 0; i < n; ++i) {
        cin >> divisors[i];
    }
    while (sz(divisors) > 1) {
        for (ll divisor : divisors) {
            ans[divisor] = true;
        }
        ll anterior = divisors[0];
        vll uniques;
        uniques.pb(anterior);
        for (int i = 1; i < sz(divisors); ++i) {
            if (divisors[i] != anterior) {
                uniques.pb(divisors[i]);
            }
            anterior = divisors[i];
        }
        uniques.swap(divisors);
        vll divisores;
        for(int i = 1; i < divisors.size(); i++) {
            divisores.pb(mcd(divisors[i-1],divisors[i]));
        }
        divisores.swap(divisors);
    }
    for(auto i : divisors) {
        ans[i] = true;
    }
    int val = 0;
    for (int i = 1; i <= 100; ++i) {
        if (ans[i]) {
            val++;
        }
    }
    cout << val << edl;
    return 0;
}