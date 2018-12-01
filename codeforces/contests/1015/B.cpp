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
	string s,t;
	cin>>s;
	cin>>t;
	vector <int> c;
	for (int i = 0; i < n; ++i)
	{
		int j = i;
		while(j < n && s[j] != t[i])
			++j;
		if(j == n)
		{
			cerr << t[i] << endl;
			cout << "-1\n";
			return 0;
		}
		for (int k = j; k > i; --k)
		{
			c.push_back(k);
			swap(s[k],s[k-1]);
		}
	}
	cout << c.size() << endl;
	for(int &x : c)
		cout << x << ' ';
	return 0;
}