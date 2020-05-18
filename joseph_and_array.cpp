
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = (1e9) + 7;
const int SIZE = (1e6) + 8;
const int MAX = (1e7) + 8;

ll spf[SIZE];
ll fact[MAX];
ll cnt[SIZE];


void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < SIZE; i++)
        spf[i] = i;

    for (int i = 4; i < SIZE; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < SIZE; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < SIZE; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

void primeFactorization(ll x)
{
    while (x > 1) {
        cnt[spf[x]] += 1;
        x = x / spf[x];
    }
}

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

ll ncr(ll n, ll r) {
    return fact[n]*binpow(fact[n-r]*fact[r] % MOD, MOD-2, MOD)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	fact[0] = fact[1] = 1;
	for(int i = 2; i < MAX; i++) fact[i] = i*fact[i-1]%MOD;
	sieve();
    ll n, k;
    cin >> n >> k;
    ll x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        primeFactorization(x);
    }
    
    ll ans = 1;
    
    for(int i = 2; i < SIZE; i++) {
        if(cnt[i]) {
            ans = ans * ncr(k+cnt[i]-1, k-1) % MOD;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
