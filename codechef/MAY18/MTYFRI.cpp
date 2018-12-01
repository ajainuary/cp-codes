#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector <int> T;
		vector <int> M;
		int M_sum = 0, T_sum = 0;
		for (int i = 0,a; i < n; ++i)
		{
			cin>>a;
			if(i%2 == 0)
			{
				M.push_back(a);
				M_sum += a;
			}
			else
			{
				T.push_back(a);
				T_sum += a;
			}
		}
		// cerr << T_sum << ' ' << M_sum << endl;
		sort(M.begin(), M.end());
		sort(T.begin(), T.end());
		int diff = M_sum - T_sum;
		int i = 0;
		while(i < k && i < T.size() && diff >= 0)
		{
			if(M[M.size()-i-1] > T[i])
				diff -= (M[M.size()-i-1] - T[i])<<1;
			++i;
		}
		if(diff < 0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}