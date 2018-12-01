#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int n,m;
	cin >> n >> m;
	vector <vector <int>> point(n+1, vector<int>(m));
	vector <vector <int>> actual(m, vector<int>(n));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0, a; j < n; ++j)
		{
			cin >> actual[i][j];
			point[actual[i][j]][i] = j;
		}
	}
	int i = 0;
	unsigned long long int size = 1;
	unsigned long long int ans = 0;
	while(i < n-1)
	{
		bool isNext = true;
		for (int j = 1; j < m; ++j)
		{
			if(point[actual[0][i+1]][j] - point[actual[0][i]][j] != 1)
			{
				isNext = false;
				break;
			}
		}
		if(isNext)
			++size;
		else
		{
			ans += (size * (size+1))/2;
			size = 1;
		}
		++i;
	}
	ans += (size * (size+1))/2;
	cout << ans << '\n';
	return 0;
}