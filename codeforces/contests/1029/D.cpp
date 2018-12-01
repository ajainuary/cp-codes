#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int n,k;
	cin >> n >> k;
	vector <int> a(n);
	for (int &x : a)
		cin>>x;
	vector <map<int, int>> s(9);
	for(int &x : a)
	{
		int j = 10;
		for (int i = 0; i < 9; ++i,j*=10)
		{
			int mod = ((x%k)*(j%k))%k;
			auto w = s[i].find(mod);
			if(w == s[i].end())
				s[i][mod] = 1;
			else
				++w->second;
		}
	}
	long long int count = 0;
	for(int &x : a)
	{
		int digits = floor(log10(x%k))+1;
		auto w = s[digits].find(k-(x%k));
		if(w != s[digits].end())
			count += w->second;
		if(((x%k)*(digits%k))%k + x%k == k)
			--count;
	}
	cout << (count>>1) << endl;
	return 0;
}