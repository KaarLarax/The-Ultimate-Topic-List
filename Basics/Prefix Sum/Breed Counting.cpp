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

ll prefix[MxN][3];

// Main funtion
int main() {
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");
    int q, n;
    fin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int aux;
        fin >> aux;
        prefix[i][aux - 1]++;
        for (int j = 0; j <= 2; ++j) {
            prefix[i][j] += prefix[i - 1][j];
        }
    }
    while (q--) {
        int l, r;
        fin >> l >> r;
        fout << prefix[r][0] - prefix[l - 1][0] << ' '
        << prefix[r][1] - prefix[l - 1][1] << ' '
        << prefix[r][2] - prefix[l - 1][2] << edl;
    }
    return 0;
}