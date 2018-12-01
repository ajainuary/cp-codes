#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }
int measure(vector <int> B, int n)
{
	int a = 0;
	for (int i = 0; i < n-1; ++i)
	{
		if(B[i] != B[i+1])
			++a;
	}
	return a;
}
int main()
{
	FAST_IO
	int a,b,x;
	cin>>a>>b>>x;
	vector <int> B(a+b, 0);
	B[0] = (x%2 == 0) ? 0 : 1;
	--b;
	int i = 1;
	while(x > 0)
	{
		B[i] = 1 - B[i-1];
		if(B[i] == 1)
			--b;
		else
			--a;
		++i;
		--x;
	}
	while(i < a+b)
	{
		B[i] = B[i-1];
		if(B[i] == 1)
			--b;
		else
			--a;
		++i;
	}
	int j = 0;
	while(b > 0)
	{
		cout << '1';
		--b;
		++j;
	}
	for(int k = 0; k < B.size()-j; ++k)
	{
		cout << B[k];
	}
	cout << endl;
	return 0;
}