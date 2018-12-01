#include <bits/stdc++.h>
using namespace std;

int max_length = 0;
void add(vector <int> &T, int x)
{
	auto y = upper_bound(T.begin(), T.end(), x);
	if(y == T.end())
	{
		T.push_back(x);
		++max_length;
	}
	else
	{
		*y = x;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector <pair <int, int>> D(n); // Width, Height
		for(auto &x : D)
			cin>>x.first>>x.second;
		sort(D.begin(), D.end(), [](pair<int, int> &lhs, pair<int, int> &rhs)
			{
				return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second>rhs.second);
			});
		vector <int> T;
		for(auto &x : D)
		{
			add(T, -x.second);
		}
		cout << max_length << endl;
		max_length = 0;	
	}
	return 0;
}