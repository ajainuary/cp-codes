#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int n,k;
	cin>>n>>k;
	if(k % 2 == 0)
	{
		cout<<"YES\n";
		for (int i = 0; i < n; ++i)
			cout<<'.';
		cout<<'\n';
		for (int i = 0; i < 2; ++i)
		{
			cout<<'.';
			int h = k >> 1;
			int j = 1;
			while(h > 0)
			{
				cout<<'#';
				++j;
				--h;
			}
			for (; j < n; ++j)
			{
				cout<<'.';
			}
			cout<<'\n';
		}
		for (int i = 0; i < n; ++i)
			cout<<'.';
		cout<<'\n';
	}
	else if(n - k == 2)
	{
		cout<<"YES\n";
		for (int i = 0; i < n; ++i)
			cout<<'.';
		cout<<'\n';
		for (int j = 0; j < n; ++j)
		{
			if(j == 0 || j == n-1)
				cout<<'.';
			else
				cout<<'#';
		}
		cout<<'\n';

		for (int i = 0; i < n; ++i)
			cout<<'.';
		cout<<'\n';
		for (int i = 0; i < n; ++i)
			cout<<'.';
		cout<<'\n';
	}
	else
	{
		cout<<"NO\n";
	}
	return 0;
}