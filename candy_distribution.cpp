#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = (1e9) + 7;

ll binpow(ll a, ll b, ll m = MOD) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        if(n == 0) {
            cout << 0 << "\n"; 
            continue;
        }
        int pow2n = binpow(2, n);
        int pow3n = binpow(3, n);
        int ans = (ll)(pow2n + 1) % MOD;
        ans = (ll)ans * (pow2n - 2) % MOD;

        ans = (ans - (ll)2 * (pow3n - pow2n - 1) % MOD + MOD) % MOD;

        cout << ans << "\n";
    }

    return 0;
}
