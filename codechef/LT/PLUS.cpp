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
		int n,m;
		cin>>n>>m;
		vector<vector<int>> g(n,vector<int>(m));
		for(auto &y : g)
			for(int &x : y)
				cin>>x;

		long long int max_plus = LLONG_MIN;

		for (int i = 1; i < n-1; ++i)
		{
			for (int j = 1; j < m-1; ++j)
			{
				long long int right_max = LLONG_MIN;
				long long int right = 0;
				for (int k = j+1; k < m; ++k)
				{
					right += g[i][k];
					if(right > right_max)
						right_max = right;
				}
				long long int left_max = LLONG_MIN;
				long long int left = 0;
				for (int k = j-1; k >= 0; --k)
				{
					left += g[i][k];
					if(left > left_max)
						left_max = left;
				}
				long long int down_max = LLONG_MIN;
				long long int down = 0;
				for (int k = i+1; k < n; ++k)
				{
					down += g[k][j];
					if(down > down_max)
						down_max = down;
				}
				long long int up_max = LLONG_MIN;
				long long int up = 0;
				for (int k = i-1; k >= 0; --k)
				{
					up += g[k][j];
					if(up > up_max)
						up_max = up;
				}
				// dbg(up_max)
				// dbg(down_max)
				// dbg(left_max)
				// dbg(right_max)
				long long int plus = g[i][j] + up_max + down_max + left_max + right_max;
				if(plus > max_plus)
				{
					max_plus = plus;
				}
			}
		}
		cout<<max_plus<<'\n';
	}
	return 0;
}