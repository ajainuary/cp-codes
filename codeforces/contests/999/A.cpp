#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int n,k;
	cin>>n>>k;
	vector <int> a(n);
	for(int &x : a)
		cin>>x;
	int left = 0, right = 0;
	int i = 0;
	while(i < n && a[i] <= k)
		++i;
	int j = n-1;
	while(j > i && a[j] <= k)
		--j;
	cout<<i+n-1-j<<endl;
	return 0;
}