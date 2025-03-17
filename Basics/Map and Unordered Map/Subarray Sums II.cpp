// By Kaarlarax
// codeforces/Kaarlarax
// github/KaarLarax
// youtubeKaarLarax

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define edl '\n'

map<ll, int> sum;
int n;
ll ans, x;

int main() {
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> x;
    sum[0] = 1;
    ll prefix = 0;
    for (int i = 1; i <= n; ++i) {
        ll temp;
        cin >> temp;
        prefix += temp;
        ans += sum[prefix - x];
        sum[prefix]++;
    }
    cout << ans << edl;
    return 0;
}