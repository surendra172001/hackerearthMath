#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = (1e6)+5;
const int MOD = (1e9)+7;

int dp[MAX];

void getDigits(int n, multiset<int> &s) {
    while(n) {
        int dig = n%10;
        s.insert(dig);
        n /= 10;
    }
}

void preComputation() {
    for(int i = 1; i < MAX; i++) {
        multiset<int> m;
        getDigits(i, m);
        bool flag = true;
		int j = 1;
        for(multiset<int>::iterator it = m.begin(); it != m.end(); it++) {
            if(*it != j) {
                flag = false;
                break;
            }
			j += 1;
        }
        dp[i] = flag+dp[i-1];
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	preComputation();
	int q;
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		cout << dp[r] - dp[l-1] << "\n";
	}
	return 0;
}
