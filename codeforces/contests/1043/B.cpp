#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int n;
	cin >> n;
	vector <int> x(n);
	int prev_a = 0;
	for (int i = 0,a; i < n; ++i)
	{
		cin >> a;
		x[i] = a - prev_a;
		prev_a = a;
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	dbg(x[i])
	// }
	vector <int> l;
	for (int i = 1; i <= n; ++i)
	{
		bool isPos = true;
		for (int j = i; j < n; ++j)
		{
			if(x[j] != x[j%i])
			{
				isPos = false;
				break;
			}
		}
		if(isPos)
			l.push_back(i);
	}
	cout << l.size() << '\n';
	for (int i = 0; i < l.size(); ++i)
	{
		cout << l[i] << ' ';
	}
	cout << endl;
	return 0;
}