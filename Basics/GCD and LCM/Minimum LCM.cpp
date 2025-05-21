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

int mcd(int n, int m) {
    int remainer;
    while (m != 0) {
        remainer = m;
        m = n % m;
        n = remainer;
    }
    return n;
}

int mcm(int n, int m) { return m / mcd(n, m) * n; }
int divisors(int n) {
    int cont = 0;
    for (int i = 1; i * i <= n ; ++i) {
        if (n % i == 0) {
            cont++;
            if (n / i != i) {
                cont++;
            }
        }
    }
    return cont;
}


// Main funtion
int main() {
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        // int limit = n / 2;
        // cout << "Posibles soluciones" << edl;
        // for (int i = 1; i <= limit; ++i) {
        //    cout << i << ' ' << n - i << ' ' << mcm(i, n - i) << edl;
        // }
        // cout << "Divisores" << edl;
        int targetcmc = mcm(n - 1, 1);
        int a = 1;
        for (int j = 2; j * j <= n; ++j) {
            if (n % j == 0) {
                int tempmcm = mcm(j, n - j);
                if (tempmcm < targetcmc) {
                    targetcmc = tempmcm;
                    a = j;
                }
                if (j != n / j) {
                    tempmcm = mcm(n / j, n - (n / j));
                    if (tempmcm < targetcmc) {
                        targetcmc = tempmcm;
                        a = n / j;
                    }
                }
            }
        }
        cout << a << ' ' << n - a << edl;
    }
    return 0;
}