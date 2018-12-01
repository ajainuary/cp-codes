#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int n;
	cin>>n;
	vector <pair <int, int>> s(n);
	for(auto &x : s)
		cin>>x.first >> x.second;
	int maxi=0,mini=0;
	for (int i = 1; i < n; ++i)
	{
		if((s[i].first > s[maxi].first) || (s[i].first == s[maxi].first && s[i].second < s[maxi].second))
			maxi = i;
		if((s[i].second < s[mini].second) || (s[i].second == s[mini].second && s[i].first > s[mini].first))
			mini = i;
	}
	int smaxi = (maxi != 0) ? 0 : 1, smini = (maxi != 0) ? 0 : 1;
	for (int i = 0; i < n; ++i)
	{
		if(i != maxi)
		{
			if(s[i].first > s[smaxi].first || (s[i].first == s[smaxi].first && s[i].second < s[smaxi].second))
				smaxi = i;
			if(s[i].second < s[smini].second || (s[i].second == s[smini].second && s[i].first > s[smini].first))
				smini = i;
		}
	}
	int smax = s[smini].second - s[smaxi].first;
	smaxi = (mini != 0) ? 0 : 1, smini = (mini != 0) ? 0 : 1;
	for (int i = 0; i < n; ++i)
	{
		if(i != mini)
		{
			if(s[i].first > s[smaxi].first|| (s[i].first == s[smaxi].first && s[i].second < s[smaxi].second))
				smaxi = i;
			if(s[i].second < s[smini].second || (s[i].second == s[smini].second && s[i].first > s[smini].first))
				smini = i;
		}
	}
	if(s[smini].second - s[smaxi].first > smax)
		smax = s[smini].second - s[smaxi].first;
	cout << max(0,smax) << endl;
	return 0;
}