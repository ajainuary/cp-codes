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
		int n;
		cin>>n;
		vector <vector<int>> A(n,vector<int>(n));
		for(auto &y : A)
			for(int &x : y)
				cin>>x;
		long long int max_sum = INT_MIN;
		for(int k = 0; k < n; ++k)
		{
			int j = k;
			int i = 0;
			long long int sum = 0;
			while(max(i,j) < n)
				sum += A[i++][j++];
			if(sum > max_sum)
				max_sum = sum;
		}
		for(int k = 0; k < n; ++k)
		{
			int j = 0;
			int i = k;
			long long int sum = 0;
			while(max(i,j) < n)
				sum += A[i++][j++];
			if(sum > max_sum)
				max_sum = sum;
		}
		cout<<max_sum<<'\n';
	}
	return 0;
}