#include <bits/stdc++.h>
using namespace std;
const int MOD = (1e9)+7;
 
long binpow(long a, long b, long m) {
    a %= m;
    long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		string s1, s2;
		cin >> s1 >> s2;
		long n1 = 0, n2 = 0;
		for(int i = 0; i < s1.length(); i++) {
			n1 = (10 * n1 % MOD + ((int)s1[i] - 48)) % MOD;
		}
		for(int i = 0; i < s2.length(); i++) {
			n2 = (10 * n2 % (MOD-1) + ((int)s2[i] - 48)) % (MOD-1);
		}
		// cout << n1 << " " << n2 << "\n";
		cout << binpow(n1, n2, MOD) << "\n";
	}
	return 0;
}
