#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = (1e5)+5;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		ll ans = arr[0];
		for(int i = 1; i < n; i++) ans = lcm(ans, arr[i]);
		cout << ans << "\n";
	}

    return 0;
}
