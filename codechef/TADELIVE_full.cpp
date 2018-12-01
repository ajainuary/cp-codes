#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	vector <pair <int, pair<int, int>>> T(n);
	int a;
	for(auto &x : T)
	{
		cin>>a;
		x.second.first = a;
	}
	for(auto &x : T)
	{
		cin>>a;
		x.second.second = a;
		x.first = abs(x.second.first - x.second.second);
	}
	sort(T.rbegin(), T.rend());
	int tips = 0;
	for(auto &t : T)
	{
		// cerr << "A: " << t.second.first << " B: " << t.second.second;
		if(t.second.first > t.second.second && x > 0)
		{
			// cerr << " goes to A" << endl;
			--x;
			tips += t.second.first;
		}
		else if(t.second.second > t.second.first && y > 0)
		{
			// cerr << " goes to B" << endl;
			--y;
			tips += t.second.second;
		}
		else
		{
			if(x > 0)
			{
				// cerr << " goes to A" << endl;
				--x;
				tips += t.second.first;
			}
			else
			{
				// cerr << " goes to B" << endl;
				--y;
				tips += t.second.second;
			}
		}
	}
	cout << tips << endl;
	return 0;
}