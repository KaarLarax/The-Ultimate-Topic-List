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
constexpr int MOD = 1e7 + 7;
constexpr int MxN = 1e3 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ull ans = 0ll;

void merge(vi& arr, int a, int mid, int b) {
    int n1 = mid - a + 1;
    int n2 = b - mid;
    vi x(n1 + 1), y(n2 + 1);
    for (int i = 0; i < n1; i++) {
        x[i] = arr[i + a];
    }
    for (int i = 0; i < n2; i++) {
        y[i] = arr[mid + i + 1];
    }
    y[n2] = x[n1] = INF;
    int i = 0, j = 0;
    ll tmp = 0ll;
    while (i < n1 || j < n2) {
        if (i < n1 && (j == n2 || x[i] <= y[j])) {
            arr[a + i + j] = x[i];
            i++;
        } else {
            arr[a + i + j] = y[j];
            ans = (ans + (n1 - i)) % MOD;
            j++;
        }
    }
}

void merge_sort(vi& arr, int a, int b) {
    if (a >= b) {
        return;
    }
    int mid = a + (b - a) / 2;
    merge_sort(arr, a, mid);
    merge_sort(arr, mid + 1, b);
    merge(arr, a, mid, b);
}

void solve() {
    ans = 0;
    int n;
    cin >> n;
    vi arr(n);
    for (auto& i : arr) {
        cin >> i;
    }
    merge_sort(arr, 0, n - 1);
    cout << ans << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    // vsCode;
    return 0;
}
// By KaarLarax