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
		vector <int> A(n);
		vector <int> ans(n);
		for(int &x : A)
			cin>>x;
		int pos = 0; //Length of the longest subarray ending with a positive no.
		int neg = 0; //Length of the longest subarray ending with a negative no.
		for (int i = n-1; i >= 0; --i)
			if(A[i] >= 0)
			{
				if(A[i+1] >= 0)
					neg = 0;
				pos = neg + 1;
				ans[i] = pos;
			}
			else
			{
				if(A[i+1] < 0)
					pos = 0;
				neg = pos + 1;
				ans[i] = neg;
			}

		for(int &x : ans)
			cout<<x<<' ';
		cout<<'\n';
	}
	return 0;
}