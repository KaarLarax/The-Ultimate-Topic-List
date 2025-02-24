#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vvi = vector<vector<int> >;

#define  sz(x) int(x.size())
#define  fi first
#define  se second
#define  pb emplace_back
#define  edl '\n'

constexpr int64_t LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr array<int, 4> dx{1, 0, -1, 0};
constexpr array<int, 4> dy{0, 1, 0, -1};
void solve() {
    int n;
    cin >> n;
    deque<int> dq;
    while (n--) {
        string s;
        int x;
        cin >> s;
        if (s == "push_front") {
            cin >> x;
            dq.push_front(x);
        } else if (s == "push_back") {
            cin >> x;
            dq.push_back(x);
        } else if (s == "pop_front" && !dq.empty()) {
            cout << dq.front() << edl;
            dq.pop_front();
        } else if (s == "pop_back" && !dq.empty()) {
            cout << dq.back() << edl;
            dq.pop_back();
        } else {
            cout << "empty" << edl;
        }
    }
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// By Kaarlarax
