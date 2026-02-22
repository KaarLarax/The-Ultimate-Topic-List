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

ll ans = 0;
bool isDuplicate = false;
void merge(vi &arr, int a, int m, int b) {
    int n1 = m - a + 1, n2 = b - m;
    vi x(n1), y(n2);
    for (int i = 0; i < n1; i++) {
        x[i] = arr[i + a];
    }
    for (int i = 0; i < n2; i++) {
        y[i] = arr[i + m + 1];
    }
    int i = 0, j = 0;
    while (i < n1 || j < n2) {
        if (i < n1 && (j == n2 || x[i] <= y[j])) {
            if (j != n2) {
                isDuplicate |= (x[i] == y[j]);
            }
            arr[a + i + j] = x[i];
            i++;
        } else {
            arr[a + i + j] = y[j];
            j++;
            ans += (n1 - i);
        }
    }
}

void merge_sort(vi &arr, int a, int b) {
    if (a >= b) {
        return;
    }
    int m = a + (b - a) / 2;
    merge_sort(arr, a, m);
    merge_sort(arr, m + 1, b);
    merge(arr, a, m, b);
}

void solve() {
    isDuplicate = ans = 0;
    int n;
    cin >> n;
    vi arr(n);
    for (auto &i : arr) {
        cin >> i;
    }
    if (n == 2) {
        cout << (arr[0] <= arr[1] ? "YES" :"NO") << edl;
        return;
    } else if (n == 1) {
        cout << "YES" << edl;
        return;
    }
    merge_sort(arr, 0, n - 1);
    cout << (isDuplicate || ans % 2ll == 0  ? "YES" : "NO") << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    int q = 1;
    cin >> q;
    while (q--) {
        solve();
    }
    // vsCode;
    return 0;
}
// By KaarLarax