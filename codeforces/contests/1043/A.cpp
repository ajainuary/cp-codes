#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	long long int n;
	cin >> n;
	long long int sum = 0;
	long long int max_a = 0;
	for (long long int i = 0, a; i < n; ++i)
	{
		cin >> a;
		sum += a;
		if(a > max_a)
			max_a = a;
	}
	sum = sum * 2;
	long long int ans = sum / n;
	// if(sum % n != 0)
		++ans;
	cout << max(ans, max_a) << endl;
	return 0;
}