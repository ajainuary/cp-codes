#include <bits/stdc++.h>
using namespace std;

int reps(vector <int> &cache, vector <int> &K, int x)
{
	// cerr << "CALL : " << x << endl;
	if(x == 0)
		return 0;
	if(cache[x] == -1)
	{
		// cerr << "Work\n";
		cache[x] = INT_MAX - 10000;
		for(int y : K)
		{
			// cerr << y << endl;
			if(x >= y && reps(cache, K, x-y) + 1 < cache[x])
				cache[x] = reps(cache, K, x-y) + 1;
		}
	}
	return cache[x];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector <int> H(n);
		vector <int> K(n);
		vector <int> cache(1001, -1);
		for (int i = 0,h; i < n; ++i)
		{
			cin>>h;
			H[i] = h<<1;
		}
		for (int i = 0; i < n; ++i)
			cin>>K[i];

		long long int times = 0;
		for(int x : H)
		{
			times += reps(cache, K, x);
			// cout<<reps(cache, K, x)<<' ';
		}
		// cout<<endl;
		// for (int i = 0; i < 1001; ++i)
		// {
		// 	cerr << cache[i] << ' ';
		// }
		// cerr << endl;
		cout<<times<<endl;
	}
	return 0;
}