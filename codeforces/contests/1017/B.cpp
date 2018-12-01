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
	string a,b;
	cin>>a;
	cin>>b;
	long long int p=0,q=0,r=0,s=0;
	for (int i = 0; i < n; ++i)
	{
		if(a[i] == '0' && b[i] == '0')
			++p;
		else if(a[i] == '0' && b[i] == '1')
			++q;
		else if(a[i] == '1' && b[i] == '0')
			++r;
		else
			++s;
	}
	cout << p*r + r*q + p*s << endl;
	return 0;
}