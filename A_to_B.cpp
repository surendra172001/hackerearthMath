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

    ll n;
    cin >> n;
    vector<ll> arr(n);
	ll p = 1;
	ll zCnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
		if(arr[i] == 0) {
			zCnt += 1;
		}else {
			p = p * arr[i] % MOD;
		}
    }

	ll q;
	cin >> q;

	for(int i = 0; i < q; i++) {
		ll type, id;
		cin >> type >> id;
		id--;
		if(type == 0) {
			ll val;
			cin >> val;
			if(arr[id] == 0 && val != 0) {
				zCnt -= 1;
				p = p * val % MOD;
			} else if(arr[id] != 0 && val != 0){
				p = p * binpow(arr[id], MOD-2, MOD) % MOD;
				p = p * val % MOD;
			} else if(arr[id] != 0 && val == 0) {
				zCnt += 1;
				p = p * binpow(arr[id], MOD-2, MOD) % MOD;
			}
			arr[id] = val;
		} else {
			ll ans = 1;
			if(zCnt == 0) {
				ans = p * binpow(arr[id], MOD-2, MOD) % MOD;
			} else if(zCnt != 0 && arr[id] != 0) {
				ans = 0;
			} else if(zCnt == 1 && arr[id] == 0) {
				ans = p;
			} else if(zCnt > 1){
				ans = 0;
			}
			cout << ans << "\n";
		}
	}

    return 0;
}
