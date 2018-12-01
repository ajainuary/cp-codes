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
	vector <int> A(101,0);
	for (int i = 0,x; i < n; ++i)
	{
		cin>>x;
		++A[x];
	}
	int max = 0;
	for (int i = 0; i < 101; ++i)
	{
		if(A[i] > max)
			max = A[i];
	}
	cout << max << endl;
	return 0;
}