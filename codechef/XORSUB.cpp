#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector <int> A(n);
		for(int &x : A)
			cin>>x;
		vector <bitset <1024>> F(n);
		F[0].set(A[0]);
		for (int i = 1; i < n; ++i)
		{
			F[i].set(A[i]);
			for (int j = 0; j < 1024; ++j)
			{
				if(F[i-1].test(j))
				{
					F[i].set(j);
					F[i].set(j ^ A[i]);
				}
			}
		}
		int maxor = k;
		for (int i = 0; i < 1024; ++i)
		{
			if(F[n-1].test(i))
				if((i ^ k) > maxor)
					maxor = i ^ k;
		}
		cout<<maxor<<endl;
	}
	return 0;
}