// By Kaarlarax
// codeforces/Kaarlarax
// github/KaarLarax
// youtubeKaarLarax

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define edl '\n'

// Main funtion
int main() {
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);
    map<ll, ll> modulos;
    int n;
    cin >> n;
    modulos[0] = 1;
    ll suma = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        int aux;
        cin >> aux;
        suma += aux;
        ll mod = ((suma % n) + n) % n;
        ans += modulos[mod];
        modulos[mod]++;
    }
    cout << ans << edl;
    return 0;
}