#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int n;
	cin>>n;
	vector <int> a(n);
	for(int &x : a)
		cin>>x;
	int max_prob = 1;
	int j = 1;
	for (int i = 1; i < n; ++i)
	{
		if(a[i] <= (a[i-1]<<1))
			++j;
		else
			j=1;
		if(j > max_prob)
			max_prob = j;
	}
	cout << max_prob << endl;
	return 0;
}