#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = (1e5)+5;
const int MOD = (1e9)+7;

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	ll a;
	cin >> a;
	string b;
	cin >> b;
	ll bInt = 0;
	for(char ch : b) {
		bInt = (10*bInt + (ll)(ch-'0'))%(MOD-1);
	}
	cout << binpow(a, bInt, MOD) << "\n";
	return 0;
}
