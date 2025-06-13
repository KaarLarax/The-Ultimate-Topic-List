// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

#define sz(x) int((x).size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr long long LLINF = 1e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 1e6 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int arr[MxN];

ll bs(const int& n, const double& avg) {
   auto good = [&](const double& extra) {
       int ans = 0;
       for (int i = 0; i < n - 1; i++) {
           if (1.0 * arr[i] < (avg + extra) / 2.0) {
               ans++;
           }
           if (double(ans) > double(n) / 2.0) {
               return true;
           }
       }
       return false;
   };
   ll l = 0, r = LLINF, m, ans = -1;
   while (l <= r) {
       m = l + (r - l) / 2;
       if (good(double(m) / double(n))) {
           r = m - 1;
           ans = m;
       } else {
           l = m + 1;
       }
   }
   return ans;
}

void solve() {
   int n;
   cin >> n;
   double avg = 0.0;
   for (int i = 0; i < n; i++) {
       cin >> arr[i];
       avg += arr[i];
   }
   avg /= n;
   sort(arr, arr + n);
   cout << bs(n, avg) << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q = 1;
    cin >> q;
    while (q--) solve();
    return 0;
}
// By KaarLarax
