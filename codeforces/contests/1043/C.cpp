#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	string s;
	cin >> s;
	vector <int> ans(s.length(),0);
	for (int i = 1; i < s.length(); ++i)
	{
		if(s[i] == 'a')
		{
			ans[i-1] = 1-ans[i-1];
			ans[i] = 1;
		}
	}
	for (int i = 0; i < s.length(); ++i)
	{
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}