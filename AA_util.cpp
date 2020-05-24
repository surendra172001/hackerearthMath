#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = (1e9) + 7;
const int MAX = (1e6) + 5;

int fact[MAX];
int inv[MAX];
int spf[MAX];
bool prime[MAX];

void fillSpf()
{
    spf[1] = 1;
    for (int i = 2; i < MAX; i++)
        spf[i] = i;

    for (int i = 4; i < MAX; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAX; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

void sieve()
{	
	prime[2] = true;
	for(int i = 3; i < MAX; i += 2) prime[i] = true;
    for (int p=3; p*p<MAX; p += 2) { 
        if (prime[p]) { 
            for (int i=p*p; i < MAX; i += p) 
                prime[i] = false; 
        }
    }
}


void fillFact() {
    fact[0] = fact[1] = 1;
    for(int i = 2; i < MAX; i++)
        fact[i] = (ll)i * fact[i-1];
}

void fillInv() {
    inv[1] = inv[0] = 1;
    for(int i = 2; i < MAX; ++i)
      inv[i] = (MOD - MOD/i) * (ll)inv[MOD%i] % MOD;
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

int ncr(int n, int r) {
    return (ll)fact[n]*binpow(fact[n-r]*fact[r] % MOD, MOD-2)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fillFact();
    fillInv();
    fillSpf();
    sieve();

    return 0;
}
