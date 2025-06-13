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
constexpr int MxN = 1e6 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

tuple<bool, vi, ll> good(ll m, const vector<tuple<int, int, int>>& values, int a) {
    ll suma = 0;
    vi ans1(sz(values));
    for (int i = 0; i < sz(values); ++i) {
        ll l = 1, r = m / get<0>(values[i]), globos, ans = 0;
        while (l <= r) {
            globos = l + (r - l) / 2;
            ll descansos = (globos - 1) / get<1>(values[i]);
            ll tiempoDescansos = descansos * get<2>(values[i]);
            ll tiempoInflar = (globos * get<0>(values[i]));
            if (tiempoDescansos + tiempoInflar <= m) {
                l = globos + 1;
                ans = globos;
            } else {
                r = globos - 1;
            }
        }
        ans1[i] = ans;
        suma += ans;
    }
    return make_tuple(suma >= a, ans1, suma);
}

tuple<ll, vi, ll> binarySearch(const vector<tuple<int, int, int>>& values, int a) {
    ll l = 1, r = a * 10000, m;
    tuple<ll, vi, ll> ans1(0, vi(sz(values), 0), 0);
    while (l <= r) {
        m = l + (r - l) / 2;
        auto ans = good(m, values, a);
        if (get<0>(ans)) {
            r = m - 1;
            ans1 = {m, get<1>(ans), get<2>(ans)};
        } else {
            l = m + 1;
        }
    }
    return ans1;
}

void solve() {
    int n, a;
    cin >> a >> n;
    vector<tuple<int, int, int>> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> get<0>(values[i]) >> get<1>(values[i]) >> get<2>(values[i]);
    }
    auto ans = binarySearch(values, a);
    ll sobrante = get<2>(ans) - a;
    cout << get<0>(ans) << edl;
    for (auto& item: get<1>(ans)) {
        item -= sobrante;
        if (item < 0) {
            sobrante = -item;
            item = 0;
        } else {
            sobrante = 0;
        }
        cout << item << ' ';
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