#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int a,b,x;
	cin>>a>>b>>x;
	int n = a+b;
	vector <bool> B(a+b, false);
	int s = x;
	int i = 0;
	if(s > 0)
	{
		B[0] = true;
		--b;
		++i;
	}
	while(s > 0)
	{
		B[i] = !B[i-1];
		if(B[i])
			--b;
		else
			--a;
		--s;
		++i;
	}
	if(B[i-1])
	{
		while(b > 0)
		{
			B[i] = true;
			--b;
			++i;
		}
	}
	else
	{
		while(a > 0)
		{
			B[i] = false;
			--a;
			++i;
		}
	}
	vector <bool> A(n);
	int j = 0;
	if(B[0])
	{
		while(b > 0)
		{
			A[j] = true;
			++j;
			--b;
		}
	}
	else
	{
		while(a > 0)
		{
			A[j] = false;
			++j;
			--a;
		}
	}

	for(int t = j; t < i; ++t)
	{
		A[t] = B[t-j];
	}
	for(auto x : B)
		cout << ((x) ? '1' : '0');
	cout << endl;
	for(auto x : A)
		cout << ((x) ? '1' : '0');
	cout << endl;
	return 0;
}