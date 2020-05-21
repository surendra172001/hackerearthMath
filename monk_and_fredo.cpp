
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = (1e9) + 7;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		int a, b, d;
		cin >> a >> b >> d;
        int x, y, g; 
        if(d == 0) {
            cout << 1 << "\n";
            continue;
        }
        g = gcd(a, b, x, y);
        if(d%g) {
            cout << 0 << "\n";
            continue;
        }
        a = a/g;
        b = b/g;
        d = d/g;
        gcd(b, a, x, y);
        x = (x%a + a)%a;
        int y1 = (d%a * x)%a;
        if(d < y1 * b) y1 = -1;
        int ans;
        if(y1 == -1) ans = 0;
        else ans = (d/b - y1)/a + 1;
        cout << ans << "\n";
	}
    return 0;
}
