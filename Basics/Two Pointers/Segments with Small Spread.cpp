// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vi = vector<int>;
using ii = pair<int, int>;

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

struct sta {
    vll s, mini = {LLINF}, maxi{-LLINF};
    void push(const ll& x) {
        s.push_back(x);
        maxi.push_back(::max(maxi.back(), x));
        mini.push_back(::min(mini.back(), x));
    }
    ll pop() {
        ll x = s.back();
        s.pop_back();
        mini.pop_back();
        maxi.pop_back();
        return x;
    }
    bool empty() {
        return s.empty();
    }
    ll min() {
        return mini.back();
    }
    ll max() {
        return maxi.back();
    }
};

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vll arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int l = 0;
    ll res = 0;
    sta s1, s2;
    auto good = [&]() {
        const ll maxi = max(s2.max(), s1.max());
        const ll mini = min(s2.min(), s1.min());
        return maxi - mini <= k;
    };
    auto remove = [&]() {
        if (s1.empty()) {
            while (!s2.empty()) {
                s1.push(s2.pop());
            }
        }
        s1.pop();
    };
    for (int r = 0; r < n; r++) {
        s2.push(arr[r]);
        while (!good()) {
            remove();
            l++;
        }
        res += r - l + 1;
    }
    cout << res << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    int q = 1;
    // cin >> q;
    while (q--) solve();
    return 0;
}
// By KaarLarax