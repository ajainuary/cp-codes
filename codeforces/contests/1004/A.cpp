#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

bool check(vector <int> &X, int c, int d)
{
	for(int &x : X)
	{
		if(c <= x + d - 1 && c >= x)
		{
			return false;
		}
		if(c >= x - d + 1 && c <= x)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	FAST_IO
	int n,d;
	cin>>n>>d;
	vector <int> X(n);
	for(int &x : X)
		cin>>x;
	sort(X.begin(), X.end());
	vector <int> U;
	long long int hotel = 0;
	for (int i = 0; i < n; ++i)
	{
		if(check(X, X[i]-d, d))
			U.push_back(X[i]-d);
		if(check(X, X[i]+d, d))
			U.push_back(X[i] + d);
	}
	sort(U.begin(), U.end());
	cout << distance(U.begin(), unique(U.begin(), U.end())) << endl;
	return 0;
}