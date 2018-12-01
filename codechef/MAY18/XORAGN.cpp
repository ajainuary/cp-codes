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
		int running_xor = 0;
		for (int i = 0,x; i < n; ++i)
		{
			cin>>x;
			running_xor ^= x<<1;
		}
		cout<<running_xor<<'\n';
	}
	return 0;
}