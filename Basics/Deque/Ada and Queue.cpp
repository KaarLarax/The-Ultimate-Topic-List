#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    deque<int> dq;
    int n;
    cin >> n;
    bool band = true;
    while (n--) {
        string s;
        int x;
        cin >> s;
        if ((s == "push_back" && band) || (s == "toFront" && !band)) {
            cin >> x;
            dq.push_back(x);
        } else if ((s == "push_back" && !band) || (s == "toFront" && band)) {
            cin >> x;
            dq.push_front(x);
        } else if (s == "reverse") {
            band = !band;
        } else if (dq.empty()) {
            cout << "No job for Ada?" << edl;
        } else if ((s == "back" && band) || (s == "front" && !band)) {
            cout << dq.back() << edl;
            dq.pop_back();
        } else if ((s == "back" && !band) || (s == "front" && band)) {
            cout << dq.front() << edl;
            dq.pop_front();
        }
    }
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}

// By KaarLarax