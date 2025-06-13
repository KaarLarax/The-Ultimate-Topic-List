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
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int arr[MxN];

int lbinarySearch(const int& n, const int&k) {
    int l = 0, r = n - 1, m, ans = -1;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (arr[m] < k) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans + 1;
}
int rbinarySearch(const int& n, const int&k) {
    int l = 0, r = n - 1, m, ans = n;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (arr[m] > k) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        cout <<  rbinarySearch(n, r) - lbinarySearch(n, l) << ' ';
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