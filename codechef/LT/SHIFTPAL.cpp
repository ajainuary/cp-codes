#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int half = s.length() >> 1;
		bool flag = true;
		int pal = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			//shift
			char tmp = s[0];
			for (int j = 0; j < s.length() - 1; ++j)
			{
				s[j] = s[j+1];
			}
			s[s.length()-1] = tmp;
			//check
			int k = 0;
			while(k < half && s[k] == s[s.length() - 1 - k])
				++k;
			if(k == half)
				++pal;
		}
		cout<<pal<<'\n';
	}
	return 0;
}