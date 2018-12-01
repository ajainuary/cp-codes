#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int n,m;
	cin>>n>>m;
	vector <int> a(n);
	vector <int> r(m,0);
	vector<int> mov(m,0);
	for(int &x : a)
	{
		cin>>x;
		++r[x % m];
	}
	long long int moves = 0;
	int req =  n / m;
	for (int i = 0; i < m<<1; ++i)
	{
		if(r[i % m] > req)
		{
			moves += r[i] - req;
			mov[i % m] = r[i] - req;
			r[(i+1) % m] += r[i] - req;
			r[i % m] = req;
		}
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	if(a[i % m])
	// }
	cout << moves << endl;
	return 0;
}