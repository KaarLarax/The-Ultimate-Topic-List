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

ull result = 0;
vi merge(vi& a, vi&  b) {
    vi ans;
    ans.reserve(sz(a)+ sz(b));
    int l = 0, r = 0;
    while (l < sz(a) || r < sz(b)) {
        if ((l < sz(a)) && (r >= sz(b) || a[l] <= b[r])) {
            ans.pb(a[l]);
            l++;
        } else { 
            ans.pb(b[r]);
            r++;
            if (l < sz(a)) {
                result += sz(a) - l;
            }
        }
    }
    return ans;
}

vi merge_sort(vi& arr, const int& p, const int& r) {
    if (p > r) {
        return {};
    }
    if (p == r) {
        return {arr[p]};
    }
    int mid = p + (r - p) / 2;
    vi a = merge_sort(arr, p, mid), b = merge_sort(arr, mid + 1, r);
    return merge(a, b);
}

void solve() {
    int n;
    cin >> n;
    vi arr(n);
    for (int& i: arr) {
        cin >> i;
    }
    arr = merge_sort(arr, 0, sz(arr) - 1);
    cout << result << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    int q = 1;
    cin >> q;
    while (q--) {
        result = 0;
        solve();
    }
    // vsCode;
    return 0;
}
// By KaarLarax