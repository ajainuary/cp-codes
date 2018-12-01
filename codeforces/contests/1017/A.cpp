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
	vector <pair<int, int>> t(n);
	for (int i = 0,a,b,c,d; i < n; ++i)
	{
		cin>>a>>b>>c>>d;
		t[i] = {a+b+c+d, i};
	}
	sort(t.rbegin(), t.rend());
	int rank = 1;
	if(t[0].second == 0)
		cout << 1 << endl;
	int same = 1;
	for (int i = 1; i < n; ++i)
	{
		if(t[i].first != t[i-1].first)
		{
			rank += same;
			same = 1;
		}
		else
			++same;
		if(t[i].second == 0)
			cout << rank << endl;
	}
	return 0;
}