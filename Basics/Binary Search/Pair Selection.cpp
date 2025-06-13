#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

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

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 1e6 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

vector<pair<int, int>> arr;
double bs(const int& n, const int& k) {
    double l = 0.00, r = 1e5, m;
    auto good = [&](const double x) {
        double ans = 0.00;
        vector<double> vans(n);
        for (int i = 0; i < n; ++i) {
            vans[i] = arr[i].fi - (x * arr[i].se);
        }
        priority_queue<double> pq(vans.begin(), vans.end());
        for (int i = 0; i < k; ++i) {
            ans += pq.top();
            pq.pop();
        }
        return ans / k >= 0.00;
    };
    for (int i = 0; i < 100; ++i) {
        m = l + (r - l) / 2.00;
        if (good(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    return l + (r - l) / 2.00;
}

void solve() {
    int n, k;
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].fi >> arr[i].se;
    }
    cout << fixed << setprecision(10) <<  bs(n, k) << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q = 1;
    // cin >> q;
    while (q--) solve();
    return 0;
}
// By KaarLarax
