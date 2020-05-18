
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = (1e9) + 7;

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

	int t;
	cin >> t;

	while(t--) {
		ll x;
		cin >> x;
		vector<ll> a(x);
		vector<ll> p(x);
		for(int i = 0; i < x; i++) cin >> a[i];
		for(int i = 0; i < x; i++) cin >> p[i];

		ll ans = 1;
		for(int i = 0; i < x; i++) {
			ll r = (binpow(a[i], p[i]+1, MOD) - a[i] + MOD)%MOD;
			r = r * binpow(a[i] - 1, MOD-2, MOD) % MOD;
			ans = ans * r % MOD;
		}

		cout << ans << "\n";

	}

    return 0;
}
