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
constexpr int MxN = 3e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int q, aux, hetero = 0, homo = 0;
    map<int, int> mp;
    string str;
    cin >> q;
    while (q--) {
        cin >> str >> aux;
        if (str == "insert") {
            mp[aux]++;
            if (mp[aux] == 1) {
                homo++;
            } else if (mp[aux] == 2) {
                hetero++;
            }
        } else {
            mp[aux]--;
            if (mp[aux] == 1) {
                hetero--;
            } else if (mp[aux] == 0) {
                homo--;
            }
        }
        if (homo > 1 && hetero > 0) {
            cout << "both" << edl;
        } else if (homo > 1 && hetero == 0) {
            cout << "hetero" << edl;
        } else if (homo <= 1 && hetero > 0) {
            cout << "homo" << edl;
        } else {
            cout << "neither" << edl;
        }
    }
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