// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'
#define vsCode cout << flush, system("Pause")

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 1e3 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int ans = 0;
void merge(vi& arr, int l, int m, int r) {
    int n1 = m - l;
    int n2 = r - m;
    vi a(n1 + 1), b(n2 + 1);
    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        b[i] = arr[m + i];
    }
    a[n1] = b[n2] = INF;

    int i = 0, j = i;
    for (int k = l; k < r; k++) {
        if (a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        ans++;
    }
}

void merge_sort(vi& arr, int l, int r) {
    if (l + 1 >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m, r);
    merge(arr, l, m, r);
}

void solve() {
    int n;
    cin >> n;
    vi arr(n);
    for (auto& i: arr) {
        cin >> i;
    }
    merge_sort(arr, 0, n);
    for (auto i: arr) {
        cout << i << ' ';
    }
    cout << edl << ans << edl;
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
    // vsCode;
    return 0;
}
// By KaarLarax