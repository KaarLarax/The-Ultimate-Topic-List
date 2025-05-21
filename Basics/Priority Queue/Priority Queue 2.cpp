// By KaarLarax
// codeforces/Kaarlarax
// github/KaarLarax
// youtube/KaarLarax

#include  <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vvi = vector<vi>;

#define sz(x) int(x.size())
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
    int n, q, a, b, c;
    cin >> n >> q;
    priority_queue<int> nums[n];
    while (q--) {
        cin >> a >> b;
        if (a == 0) {
            cin >> c;
            nums[b].push(c);
        } else if (a == 1) {
            if (!nums[b].empty()) {
                cout << nums[b].top() << edl;
            }
        } else {
            if (!nums[b].empty()) {
                nums[b].pop();
            }
        }
    }
}
