#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		if(n == 1 || n == 2 || n == 3) {
			cout << 1 << "\n";
			continue;
		}
		ll level = 1;
		ll nodes = 2;
		ll sum = 2;
		while(sum <= n) {
			level += 1;
			nodes = (2*nodes);
			sum += nodes*level;
		}

		ll ans1 = 2*level-1;
		ll ans2 = 2*(level-1)-1;
		sum -= level*nodes;
		// cout << sum << "\n";
		ll k = n - sum;
		if(k >= 2*level) {
			cout << ans1 << "\n";
		} else if(k >= level) {
			cout << max(ans2, level) << "\n";
		} else {
			cout << ans2 << "\n";
		}
	}
}

