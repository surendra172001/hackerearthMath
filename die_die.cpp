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
		ll n;
		cin >> n;
		ll ans = binpow(2, n, MOD);
		ans = 2 * binpow(ans, MOD-2, MOD) % MOD;
		cout << ans << "\n";
	}

    return 0;
}
