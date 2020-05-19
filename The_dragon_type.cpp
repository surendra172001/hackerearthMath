#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = (1e5)+5;

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

	ll n, p;
	cin >> n >> p;
	int cnt[p+1] = {};
	ll x;
	for(int i = 0; i < n; i++) {
		cin >> x;
		cnt[x%p] += 1;
	}
	ll sum = 0;
	for(int i = 1; i <= p; i++) {
		if(cnt[i]) {
			int inv = binpow(i, p-2, p);
			int r = -1;
			if(cnt[inv]) {
				r = (cnt[i] <= cnt[inv] ? i : inv);
			}
			if(r != -1) {
				cnt[r] = 0;
			}
		}
		sum += cnt[i];
	}
	sum += cnt[0];
	cout << sum << "\n";
    return 0;
}
