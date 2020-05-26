#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;


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
