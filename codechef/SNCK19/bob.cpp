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
vector <int> adj[100001];
bool visit[100001];
const int mod = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,i,m,t,a[101],b[101];
	cin>>t;
	while(t--)
	{
		ll s1=0,s2=0,c=0,d=0;
		cin>>n>>m;
		FOR(0,n,1)
		{
			cin>>a[i];
			c+=a[i];
			if(a[i]==0)
				s1++;
		}
		FOR(0,m,1)
		{
			cin>>b[i];
			d+=b[i];
			if(b[i]==0)
				s2++;
		}
		int k1=n-1,k2=m-1;
		if(n-s1 != m-s2)
			cout<<"Alice\n";
		else
		{
			sort(a,a+n);
			sort(b,b+m);
			int ta[101],tb[101];
			int tn = 0;
			for (int i = 0; i < n; ++i)
			{
				if(a[i] != 0)
				{
					ta[tn] = a[i];
					++tn;
				}
			}
			tn = 0;
			for (int i = 0; i < m; ++i)
			{
				if(b[i] != 0)
				{
					tb[tn] = b[i];
					++tn;
				}
			}
			int f=0;
			FOR(0,tn,1)
			{
				if(ta[i]!=tb[i])
				{
					cout<<"Alice\n";
					f=1;
					break;
				}
			}
			if(f==0)
			{
				cout<<"Bob\n";

			}
		}
	}
	return 0;
}