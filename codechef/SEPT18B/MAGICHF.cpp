#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,x,s;
		cin >> n >> x >> s;
		for (int i = 0,a,b; i < s; ++i)
		{
			cin >> a >> b;
			if(a == x)
				x = b;
			else if(b == x)
				x = a;
		}
		cout << x << '\n';
	}
	return 0;
}