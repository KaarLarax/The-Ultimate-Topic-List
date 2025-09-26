#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 1e6 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    map<int, int> elements;
    auto add = [&](int& x) {
        elements[x]++;
    };
    auto remove =[&](int& x) {
        elements[x]--;
        if (!elements[x]) {
            elements.erase(x);
        }
    };
    auto good = [&](int& x) {
        if (elements.find(x) == elements.end()) {
            return true;
        }
        return elements[x] == 1;
    };
    int l = 0;
    int ans = 0;
    for (int r = 0; r < n; r++) {
        add(arr[r]);
        while(!good(arr[r])) {
            remove(arr[l]);
            l++;
        }
        if (good(arr[r])) {
            ans = max(ans, sz(elements));
        }
    }
    cout << ans << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
// By KaarLarax