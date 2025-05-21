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
    int q;
    priority_queue<ll, vector<ll>, greater<>> pq;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        if (s == "push") {
            ll n;
            cin >> n;
            pq.push(n);
        } else if (s[0] == 't') {
            cout << pq.top() << edl;
        } else if (s[0] == 'p') {
            pq.pop();
        }
    }
}
