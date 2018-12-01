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
		vector <long long int> D(n);
		//first: Forward, second: Backward
		vector <pair<long long int, long long int>> maxs(n);
		vector <pair<long long int, long long int>> mins(n);

		for(long long int &x : D)
			cin>>x;
		long long int max_sum = LLONG_MIN;
		long long int sum = 0;
		for(int i = 0; i < n; ++i)
		{
			if(sum < 0)
				sum = 0;

			sum += D[i];

			if(sum > max_sum)
				max_sum = sum;

			maxs[i].first = max_sum;
		}
		max_sum = LLONG_MIN;
		sum = 0;
		for(int i = n-1; i >= 0; --i)
		{
			if(sum < 0)
				sum = 0;

			sum += D[i];

			maxs[i].second = max_sum;

			if(sum > max_sum)
				max_sum = sum;
		}
		long long int min_sum = LLONG_MAX;
		sum = 0;
		for(int i = 0; i < n; ++i)
		{
			if(sum > 0)
				sum = 0;

			sum += D[i];

			if(sum < min_sum)
				min_sum = sum;

			mins[i].first = min_sum;
		}
		min_sum = LLONG_MAX;
		sum = 0;
		for(int i = n-1; i >= 0; --i)
		{
			if(sum > 0)
				sum = 0;

			sum += D[i];

			mins[i].second = min_sum;
			
			if(sum < min_sum)
				min_sum = sum;
		}
		long long int delish = LLONG_MIN;
		for (int i = 0; i < n-1 ; ++i)
		{
			
			if(abs(maxs[i].first - mins[i].second) > delish)
				delish = abs(maxs[i].first - mins[i].second);

			if(abs(maxs[i].second - mins[i].first) > delish)
				delish = abs(maxs[i].second - mins[i].first);
		}

		cout<<delish<<'\n';
	}
	return 0;
}