#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector <string> A(n);

	for(auto &y : A)
		cin>>y;

	vector <vector <int>> G(n,vector <int> (m, 0));

	for (int i = 0; i < m; ++i)
		G[n-1][i] = (A[n-1][i] == '1') ? 1 : 0;

	for(int i = n-2; i >= 0; --i)
		for (int j = 0; j < m; ++j)
			if(A[i][j] == '1')
				G[i][j] = G[i+1][j] + 1;
	long long int count = 0;
	
	for(auto &y : G)
	{
		int prev = 0;
		for(auto &x : y)
		{
			prev = min(prev+1, x);
			count += prev;
		}
	}

	cout << count << endl;
	return 0;
}