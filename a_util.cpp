#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = (1e9) + 7;
const int MAX = (1e6) + 5;

int fact[MAX];

void fillFact() {
    fact[0] = fact[1] = 1;
    for(int i = 2; i < MAX; i++)
        fact[i] = (ll)i * fact[i-1];
}


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

	inv[1] = inv[0] = 1;
	for(int i = 2; i < MAX; ++i)
		inv[i] = (MOD - MOD/i) * (ll)inv[MOD%i] % MOD;
  return 0;
}

