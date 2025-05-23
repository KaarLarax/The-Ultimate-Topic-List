#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e4 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bitset<MxN> ans[MxN];

void solve() {
    list<int> list1;
    int n;
    cin >> n;
    while (n--) {
        string a;
        cin >> a;
        if (a == "insert") {
            int as;
            cin >> as;
            list1.emplace_front(as);
        } else if (a == "delete") {
            int as;
            cin >> as;
            auto it = find(list1.begin(), list1.end(), as);
            if (it != list1.end()) {
                list1.erase(it);
            }
        } else if (a == "deleteFirst") {
            if (!list1.empty()) {
                list1.pop_front();
            }
        } else {
            if (!list1.empty()) {
                list1.pop_back();
            }
        }
    }
    for (auto i = list1.begin(); i != list1.end(); i++) {
        auto item = i;
        cout << *i << (++item != list1.end()? " ": "");
    }
    cout << edl;
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