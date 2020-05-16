#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = (1e5)+5;
const int MOD = (1e9)+7;

ll fact[MAX];

ll binpow(ll a, ll b, ll m) {
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
int main() {
	fact[0] = fact[1] = 1;
	for(int i = 2; i < MAX; i++) fact[i] = i*fact[i-1]%MOD;

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		ll ans = fact[k];
		ll p = binpow(fact[k-n], MOD-2, MOD);
		// cout << p << " ";
		ans = ans * p % MOD;
		cout << ans << "\n";
	}
}
