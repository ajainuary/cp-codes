#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }
vector <int> group(256, -1);
array<int, 100005> p;
int main()
{
	FAST_IO
	int n,k;
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>p[i];
	}
	for(int i = 0; i < n; ++i)
	{
		int gr = 0;
		int j = p[i];
		while(j >= 0 && gr < k && group[j] == -1)
		{
			--j;
			++gr;
		}
		
		if(p[i] - group[j] < k)
			j = group[j];
		else
			++j;
		int low = j;
		for (; j <= p[i]; ++j)
		{
			group[j] = low;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<group[p[i]]<<' ';
	}
	cout<<'\n';
	return 0;
}