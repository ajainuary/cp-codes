#include <bits/stdc++.h>
using namespace std;
array<long long int, 100005> a;
array<long long int, 100005> b;
const int MOD = 1000000007;

int main()
{
	//Precomputation
	a[1] = 1;
	a[2] = 0;
	b[1] = 0;
	b[2] = 1;
	for (int i = 3; i < 100005; ++i)
	{
		a[i] = (a[i-1] + a[i-2]) % MOD;
		b[i] = (b[i-1] + b[i-2]) % MOD;
	}

	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		array<long long int, 100005> A;
		array<long long int, 100005> B;
		for (int i = 0; i < m; ++i)
			cin>>A[i];

		for (int i = 0; i < m; ++i)
			cin>>B[i];
		long long int result = 0;
		for (int i = 0; i < m; ++i)
			result = (result + ((((A[i]*m)%MOD)*a[n])%MOD) + ((((B[i]*m)%MOD)*b[n])%MOD))%MOD;

		cout<<result<<'\n';
	}
	return 0;
}