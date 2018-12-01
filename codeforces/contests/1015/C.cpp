#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	long long int n,m;
	cin>>n>>m;
	// vector <int> a(n);
	// vector <int> b(n);
	vector <int> c(n);
	long long int suma=0;
	long long int sumb=0;
	for (int i = 0,a,b; i < n; ++i)
	{
		cin>>a>>b;
		suma += a;
		sumb += b;
		c[i] = a-b;
	}
	if(sumb > m)
	{
		cout << "-1\n";
		return 0;
	}
	sort(c.rbegin(), c.rend());
	long long int comp = suma - m;
	long long int done = 0;
	int k = 0;
	while(done < comp)
	{
		done += c[k];
		++k;
	}
	cout << k << endl;
	return 0;
}