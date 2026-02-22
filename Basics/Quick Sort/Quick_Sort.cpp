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


int partition(vii& arr, int a, int b) {
    int x = arr[b].fi;
    int i = a - 1;
    for (int j = a; j < b; j++) {
        if (arr[j].fi <= x) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[b]);
    return i + 1;
}

void quick_sort(vii& arr, int a, int b) {
    if (a >= b) {
        return;
    }
    int piv = partition(arr, a, b);
    quick_sort(arr, a, piv - 1);
    quick_sort(arr, piv + 1, b);
}

void solve() {
    int n;
    cin >> n;
    vii arr(n);
    map<int, vi> tmp, ans;
    char aux;
    for (int i = 0; i < n; i++) {
        cin >> aux >> arr[i].fi;
        arr[i].se = (int) aux;
        tmp[arr[i].fi].pb(arr[i].se);
    }
    quick_sort(arr, 0, n - 1);
    for (auto& i : arr) {
        ans[i.fi].pb(i.se);
    }
    cout << (ans == tmp ? "S" : "Not s") << "table" << edl;
    for (auto& i : arr) {
        cout << (char) i.se << ' ' << i.fi << edl;
    }
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