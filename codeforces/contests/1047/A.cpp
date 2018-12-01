#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int n;
	cin >> n;
	if(n % 3 == 0)
		cout << "1 1 " << n-2 << '\n';
	else
		cout << "1 2 " << n-3 << '\n';
	return 0;
}