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
	string s;
	cin>>s;
	vector <bool> present(n,true);
	
	int i = 0, j = 0;
	while(i < k && j < 26)
	{
		for (int p = 0; p < s.length() && i < k; ++p)
		{
			if(s[p] == 'a' + j)
				++i,present[p] = false;
		}
		++j;
	}

	for (int i = 0; i < s.length(); ++i)
	{
		if(present[i])
			cout << s[i];
	}
	cout << endl;
	return 0;
}