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
	vector <int> av(n);
	for (int i = 0; i < n; ++i)
	{
		char c;
		cin>>c;
		av[i] = c - 'a' + 1;
	}
	sort(av.begin(), av.end());
	int wt = 0;
	int j = 0;
	int prev = -1;
	for(int i = 0;i < n && j < k; ++i)
	{
		if(av[i] - prev > 1)
		{
			++j;
			wt += av[i];
			prev = av[i];
		}
	}
	if(j < k)
	{
		cout << "-1\n";
	}
	else
		cout << wt << endl;
	return 0;
}