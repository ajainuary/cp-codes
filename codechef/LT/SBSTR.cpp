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
		int k;
		cin>>s>>k;
		vector<vector<int>> count(s.length()+1, vector<int>(26, 0));
		for(int i = 1; i < s.length()+1; ++i)
		{
			count[i] = count[i-1];
			++count[i][s[i-1] - 'a'];
		}
		long long int ans = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			for (int j = i+1; j < s.length()+1; ++j)
			{
				// cerr<<i<<' '<<j<<endl;
				int cur_k = 0;
				int freq = 0;
				int flag = 0;
				for(int m = 0; m < 26; ++m)
				{
					if(count[i][m] == count[j][m])
						continue;
					if(freq == 0 || count[j][m] - count[i][m] == freq)
					{
						freq = count[j][m] - count[i][m];
						++cur_k;
					}
					else
					{
						// cerr<<"fail "<<count[j][m] - count[i][m]<<' '<< freq <<endl;
						flag = 1;
						break;
					}
				}
				if(flag == 0 && cur_k > k-1)
				{
					// dbg(freq)
					++ans;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}