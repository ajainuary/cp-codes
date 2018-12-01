#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int n;
	long double m;
	cin>>n>>m;
	vector <long double> a(n);
	vector <long double> b(n);
	for(auto &x : a)
	{
		cin >> x;
		if(x == 1)
		{
			cout << "-1\n";
			return 0;
		}
	}
	for(auto &x : b)
	{
		cin >> x;
		if(x == 1)
		{
			cout << "-1\n";
			return 0;
		}
	}
	long double p = 0;
	p = m/(b[0]-1);
	for (int i = n-1; i > 0; --i)
	{
		p = (p*a[i] + m)/(a[i]-1);
		p = (p*b[i] + m)/(b[i]-1);
	}
	cout.precision(100);
	p = (p*a[0] + m)/(a[0]-1);
	cout << p << endl;
	return 0;
}