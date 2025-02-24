// By KaarLarax
// codeforces/Kaarlarax
// github/KaarLarax
// youtube/KaarLarax

#include  <bits/stdc++.h>

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

// Main function
int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    queue<pair<string, int>> q;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        q.push({s, x});
    }
    int ans = 0;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        v.second -= m;
        if (v.second > 0) {
            ans += m;
            q.push(v);
        } else {
            ans += m - (v.second * -1);
            cout << v.first << ' ' << ans << edl;
        }
    }
    return 0;
}