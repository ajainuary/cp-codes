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
	string s;
	cin>>s;
	for(int i = 1;i <= n; ++i)
	{
		if(n % i == 0)
		{
			for (int j = 0; j < i>>1; ++j)
			{
				swap(s[j], s[i-1-j]);
			}
		}
	}
	cout << s << endl;
	return 0;
}