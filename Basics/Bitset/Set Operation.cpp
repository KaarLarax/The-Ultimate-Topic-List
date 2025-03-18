#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;

#define sz(x) int((x).size())
#define fi first
#define se second
#define pb push_back

const long long LLINF = 2000000000000000000LL;
const int INF = 2000000000;
const int MOD = 1000000007;
const int MxN = 300005;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

bitset<1001> ans[10005];

void solve() {
    int n, aux, temp, x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &aux);
        for (int j = 0; j < aux; ++j) {
            scanf("%d", &temp);
            ans[temp].set(i);
        }
    }
    scanf("%d", &aux);
    while (aux--) {
        scanf("%d %d", &temp, &x);
        if ((ans[temp] & ans[x]).any()) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    int q = 1;
    // scanf("%d", &q);
    while (q--) {
        solve();
    }
    return 0;
}

// By KaarLarax
