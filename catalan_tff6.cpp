#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = (1e9) + 9;
const int MAX = (2e5) + 5;

ll fact[MAX];

ll binpow(ll a, ll b, ll m) {
	if(a == 0) return 0;
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
	fact[0] = fact[1] = 1;
	for(int i = 2; i < MAX; i++) fact[i] = i*fact[i-1]%MOD;

	int n;
	cin >> n;

	ll ans = fact[2*n] * binpow(fact[n] * fact[n+1] % MOD, MOD - 2, MOD) % MOD;

	cout << ans << "\n";

    return 0;
}
