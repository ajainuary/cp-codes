#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,d;
	cin>>n>>d;
	vector<int> L(n);
	
	for(int &x : L)
		cin>>x;

	sort(L.begin(), L.end());

	if((n&1) == 0)
	{
		// n is even, so order doesn't matter
		int pairs = 0;
		for (int i = 0; i < n-1; ++i)
			if(L[i+1] - L[i] <= d)
			{
				++pairs;
				++i;
			}
		cout<<pairs<<'\n';
	}
	else
	{
		// n is odd so we can either leave the first one or the last one
		int fwd_pairs = 0, rev_pairs = 0;
		for (int i = 0; i < n-1; ++i)
			if(L[i+1] - L[i] <= d)
			{
				++fwd_pairs;
				++i;
			}

		for (int i = n-1; i > 0; --i)
			if(L[i] - L[i-1] <= d)
			{
				++rev_pairs;
				--i;
			}
		cout<<max(fwd_pairs, rev_pairs)<<'\n';
	}
	return 0;
}