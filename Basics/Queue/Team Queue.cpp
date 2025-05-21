// By KaarLarax
// codeforces/Kaarlarax
// github/KaarLarax
// youtube/KaarLarax

#include  <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vvi = vector<vi>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr int64_t LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr array<int, 4> dx{1, 0, -1, 0};
constexpr array<int, 4> dy{0, 1, 0, -1};


// Main function
int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    for (int z = 1; true; z++) {
        int n;
        cin >> n;
        if (n == 0) {
            return 0;
        }
        cout << "Scenario #" << z << edl;
        map<int, int> teams;
        for (int i = 1; i <= n; i++) {
            int c;
            cin >> c;
            for (int j = 0; j < c; j++) {
                int aux;
                cin >> aux;
                teams[aux] = i;
            }
        }
        vector<queue<int> > teamqueue(n + 1);
        queue<int> generalqueue;
        while (true) {
            string s;
            cin >> s;
            if (s == "STOP") {
                break;
            }
            if (s == "ENQUEUE") {
                int val;
                cin >> val;
                if (teamqueue[teams[val]].empty()) {
                    generalqueue.push(teams[val]);
                }
                teamqueue[teams[val]].push(val);
            } else {
                int gfront = generalqueue.front();
                int target = teamqueue[gfront].front();
                cout << target << edl;
                teamqueue[gfront].pop();
                if (teamqueue[gfront].empty()) {
                    generalqueue.pop();
                }
            }
        }
        cout << edl;
    }
}
