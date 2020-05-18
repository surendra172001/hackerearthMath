
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = (1e9) + 7;


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
		vector<ll> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		ll g = a[0];
		for(ll x : a) g = __gcd(x, g);
		int q;
		cin >> q;
		for(int i = 0; i < q; i++) {
			ll l, r;
			cin >> l >> r;
			ll p = (l-1)/g;
			ll s = r/g;
			cout << s-p << "\n";
		}

	}

    return 0;
}
