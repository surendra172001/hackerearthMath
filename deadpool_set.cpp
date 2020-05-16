

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = (1e9) + 7;
const int MAX = (1e6) + 5;

bool present[MAX];
ll dp[MAX];
int spf[MAX];

void sieve()
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

void getFactorization(int x, map<int, int> &m)
{
    while (x != 1) {
        m[spf[x]] += 1;
        x = x / spf[x];
    }
}

void generateDivisors(int curIndex, int curDivisor, vector< pair<int, int> >& arr, set<int> &divisors){ 
    if (curIndex == arr.size()) { 
        divisors.insert(curDivisor);
        return; 
    } 
  
    for (int i = 0; i <= arr[curIndex].second; ++i) { 
        generateDivisors(curIndex + 1, curDivisor, arr, divisors); 
        curDivisor *= arr[curIndex].first; 
    } 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	sieve();
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        present[arr[i]] = true;
        dp[arr[i]] = 1;
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
		map<int, int> m;
		getFactorization(arr[i], m);
		vector<pair<int, int> > v;
		for(pair<int, int> x : m) {
			v.push_back(x);
		}
		set<int> divisors;
		generateDivisors(0, 1, v, divisors);
		int sqrtN = sqrt(arr[i]);
		set<int>::iterator it = divisors.begin();
		it++;
		for(; it != divisors.end() && (*it) <= sqrtN; it++) {
			int x = *it;
			int y = arr[i]/x;
			if(present[x] && present[y]) {
			    int p = (dp[x]*dp[y])%MOD;
			    p = (x == y ? p : (2*p)%MOD);
			    dp[arr[i]] = (dp[arr[i]] + p)%MOD;
			}
		}
    }
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		if(arr[i] > 1)
			sum = (sum + dp[arr[i]])%MOD;
	}
	cout << sum << "\n";
    return 0;
}
