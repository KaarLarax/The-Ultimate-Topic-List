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
constexpr int MxN = 1e6 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool good(int m, vi arr, string a, string b) {
    for (int i = 0; i < m; i++) {
        a[arr[i] - 1] = '`';
    }
    string a1;
    for (char i : a) {
        if (i != '`') {
            a1 += i;
        }
    }
    string existencia;
    int index = 0;
    for (int i = 0; i < sz(a1); ++i) {
        if (index < sz(b) && a1[i] == b[index]) {
            index++;
        }
    }
    return index == sz(b);
}

int bS(string a, string b, vi arr) {
    int l = 0, r = sz(a), m, ans = 0;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (good(m, arr, a, b)) {
            l = m + 1;
            ans = m;
        } else {
            r = m - 1;
        }
    }
    return ans;
}

void solve() {
    string a, b;
    cin >> a >> b;
    vi arr(sz(a));
    for (int i = 0; i < sz(a); ++i) {
        cin >> arr[i];
    }
    cout << bS(a, b, arr) << edl;
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