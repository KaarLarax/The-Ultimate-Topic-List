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
    int n;
    map<int, int> buckets;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        buckets[arr[i]]++;
    }
    int ans = 0;
    for (const pii& p11: buckets) {
        ans += (p11.second - p11.first < 0? p11.second: p11.second - p11.first);
    }
    cout << ans << edl;
    return 0;
}