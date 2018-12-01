#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int p;
		cin>>p;
		int menus = 0;
		for (int i = 0; i < 12; ++i)
		{
			if((p&1) == 1)
				++menus;
			p >>= 1;
		}
		int add = 2;
		while(p > 0)
		{
			if((p&1) == 1)
				menus += add;
			add <<= 1;
			p >>= 1;
		}
		cout<<menus<<'\n';
	}
	return 0;
}