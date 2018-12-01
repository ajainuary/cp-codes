#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	long long int n,h,a,b,k;
	cin>>n>>h>>a>>b>>k;
	for (long long int i = 0,p,q,r,s; i < k; ++i)
	{
		long long int d=0;
		cin>>p>>q>>r>>s;
		if(p == r)
		{
			cout << abs(q-s) << '\n';
			continue;
		}
		if(q > b)
		{
			d+=q-b;
			q=b;
		}
		else if(q < a)
		{
			d+=a-q;
			q=a;
		}
		if(s > b)
		{
			d+=s-b;
			s=b;
		}
		else if(s < a)
		{
			d+=a-s;
			s=a;
		}
		cout << d + abs(p-r) + abs(q-s)<< '\n';
	}
	return 0;
}