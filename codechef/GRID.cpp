#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector <vector <int>> G(n, vector <int>(n));
		vector <vector <int>> V(n, vector <int>(n,1));
		vector <vector <int>> H(n, vector <int>(n,1));
		char c;
		for (auto &x : G)
		{
			for (auto &y : x)
			{
				cin>>c;
				if(c == '.')
					y = 1;
				else
					y = 0;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			V[n-1][i] = G[n-1][i];
			H[i][n-1] = G[i][n-1];
		}
		for (int i = n-2; i >= 0; --i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(V[i+1][j] == 0 || G[i][j] == 0)
					V[i][j] = 0;
			}
		}
		for (int i = n-2; i >= 0; --i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(H[j][i+1] == 0 || G[j][i] == 0)
					H[j][i] = 0;
			}
		}
		int mirror = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(H[i][j] == 1 && V[i][j] == 1)
					++mirror;
			}
		}
		cout<<mirror<<endl;
	}
	return 0;
}