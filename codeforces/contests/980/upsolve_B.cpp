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
	cout<<"YES\n";
	for (int i = 0; i < n; ++i)
		cout<<'.';
	cout<<"\n";
	int mid = (n>>1)+1;
	if(k < n-1)
	{
		cout<<'.';
		for (int i = 1; i < mid-1; ++i)
			if(i <= k>>1)
				cout<<'#';
			else
				cout<<'.';
		
		if((k&1) == 0)
			cout<<'.';
		else
			cout<<'#';

		for (int i = 1; i < mid-1; ++i)
			if(i > mid - (k>>1) - 2)
				cout<<'#';
			else
				cout<<'.';
		cout<<".\n";
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < n; ++j)
				cout<<'.';
			cout<<'\n';
		}
	}
	else
	{
		string s,t;
		for (int i = 0; i < n; ++i)
		{
			s.push_back('.');
			t.push_back('.');
		}
		if((k&1) != 0)
			s[mid-1] = '#';
		for (int i = 0; i < k>>2; ++i)
		{
			s[i+1] = '#';
			t[i+1] = '#';
			s[n-i-2] = '#';
			t[n-i-2] = '#';
		}
		if(k == (n-2<<1))
			t[mid-1] = '#';
		if((k>>1&1) != 0)
		{
			s[(k>>2)+1] = '#';
			s[n-(k>>2)-2] = '#';
		}
		cout<<s<<'\n'<<t<<'\n';
		for (int j = 0; j < n; ++j)
				cout<<'.';
			cout<<'\n';
	}
	return 0;
}