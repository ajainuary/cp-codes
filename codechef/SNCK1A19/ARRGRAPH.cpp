#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(long long i=I;i<A;i+=B)
#define rep(I,A,B) for(long long j=I;j<=A;j+=B)
#define repp(I,A,B) for(long long j=I;j>=A;j-=B)
#define str(A) for(long long k=0;A[k]!='\0';k++)
#define pb push_back
#define mp make_pair
#define pii pair<long long,long long>
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t,n,i;
	cin>>t;
	rep(1,t,1)
	{
		cin>>n;
		int arr[51],o=0,e=0;
		FOR(0,n,1)
		{
			cin>>arr[i];
			if(arr[i]%2)
				o++;
			else
				e++;
		}
		if(o&&e)
		{
			cout<<0<<endl;
			FOR(0,n,1)
				cout<<arr[i]<<" ";
		}
		if(!o&&e)
		{
			if(n==1)
				cout<<0<<endl<<arr[0]<<endl;
			else
			{
				arr[0]=3;
				cout<<1<<endl;
				FOR(0,n,1)
					cout<<arr[i]<<" ";
			}
		}
		if(!e&&o)
		{
			int flag=0;
			FOR(0,n,1)
			{
				rep(2,sqrt(arr[i]),1)
				{
					if(arr[i]%j==0)
					{
						flag=1;
						arr[i]=2;
						cout<<1<<endl;
						for(int k=0;k<n;k++)
							cout<<arr[i]<<" ";
					}
				}
				if(flag)
					break;
			}
			if(!flag)
			{
				cout<<0<<endl;
				FOR(0,n,1)
					cout<<arr[i]<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}