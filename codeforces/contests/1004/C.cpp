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
	long long int pairs = 0;
	vector <int> A(n);
	for(int &x : A)
		cin>>x;
	vector <bool> U(100005, false);
	int uniq = 0;
	vector <int> UB(n, 0);
	for (int i = 0; i < n; ++i)
	{
		UB[i] = uniq;
		if(!U[A[i]])
		{
			++uniq;
			U[A[i]] = true;
		}
	}
	vector <int> MAXP(100005, 0);
	for(int i=0; i < n; ++i)
	{
		if(UB[i] > MAXP[A[i]])
			MAXP[A[i]] = UB[i];
	}
	for(int &x : MAXP)
		pairs += x;

	cout << pairs << endl;
	return 0;
}