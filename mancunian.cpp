#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = (1e9) + 7;
const int MAX = (1e6) + 5;
const int SIZE = (5e5) + 5;

int inv[MAX];
int a[SIZE];
int func[SIZE];
int cnt[MAX];
ll curr_val = 1;
int BLOCK;


struct Event {
	int l, r;
};

inline int getBlock(int idx) {
	return idx/BLOCK;
}


bool cmp(const Event &a, const Event &b) {
	int b1 = getBlock(a.l);
	int b2 = getBlock(b.l);
	if(b1 != b2)
		return b1 < b2;
	return a.r < b.r;
}


void add(int pos) {
	if(cnt[pos] >= 0)
		curr_val = curr_val * inv[func[cnt[pos]]] % MOD;
	cnt[pos] += 1;
	if(cnt[pos] >= 0)
		curr_val = curr_val * func[cnt[pos]] % MOD;
}


void rem(int pos) {
	if(cnt[pos] >= 0)
		curr_val = curr_val * inv[func[cnt[pos]]] % MOD;
	cnt[pos] -= 1;
	if(cnt[pos] >= 0)
		curr_val = curr_val * func[cnt[pos]] % MOD;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	inv[1] = inv[0] = 1;
	for(int i = 2; i < MAX; ++i)
		inv[i] = (MOD - MOD/i) * (ll)inv[MOD%i] % MOD;
	
	int n, c, q;

	cin >> n >> c >> q;

	BLOCK = ceil(sqrt(n));

	int a[n];
	
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i <= n; i++) cin >> func[i];


	Event query[q];
	int l, r;
	for(int i = 0; i < q; i++) {
		cin >> l >> r;
		l--, r--;
		query[i].l = l;
		query[i].r = r;
	}

	sort(query, query+q, cmp);

	curr_val = 1;
	cnt[a[0]] = 1;
    for(int i=1;i<=c;i++)
        curr_val = curr_val * func[cnt[i]] % MOD;

	ll ans = 1;
	int left = 0, right = 0;

	for(int i = 0; i < q; i++) {
		l = query[i].l;
		r = query[i].r;
		while(left < l) {
			rem(a[left]);
			left++;
		}
		
		while(left > l) {
			left--;
			add(a[left]);
		}

		while(right < r) {
			right++;
			add(a[right]);
		}

		while(right > r) {
			rem(a[right]);
			right--;
		}

		ans = ans * curr_val % MOD;
	}

	cout << ans << "\n";
	
	return 0;
}


