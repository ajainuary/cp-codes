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
		int running_gcd;
		cin>>running_gcd;
		for (int i = 1; i < n; ++i)
		{
			int x;
			cin>>x;
			running_gcd = __gcd(running_gcd, x);
		}
		if(running_gcd == 1)
			cout<<"0\n";
		else
			cout<<"-1\n";
	}
	return 0;
}