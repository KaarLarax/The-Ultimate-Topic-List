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

int getMax(ll array[], const int& n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

void countingSort(ll array[], const int& size, const int& place) {
    const int max = 10;
    int output[size];
    int count[max];

    for (int i = 0; i < max; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        count[(array[i] / place) % 10]++;
    }
    for (int i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10]-- - 1] = array[i];
    }
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

void radixsort(ll array[], const int& size) {
    int max = getMax(array, size);
    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(array, size, place);
    }
}

ll arr[1000005];

void solve() {
    int n, a, b, c, x, y;
    cin >> n >> a >> b >> c >> x >> y;
    arr[0] = a;
    for (int i = 1; i < n; i++) {
        arr[i] = int(((ll) arr[i - 1] * b + a) % c);
    }
    radixsort(arr, n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = ( (ll) ans * x + arr[i]) % y;
    }
    cout << ans << edl;
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