#include <bits/stdc++.h>
using namespace std;
const int A=1000010;
map<int,int> p;
int a[A],w[A];
vector<int> s;
void thief(int l,int r,int x){
	int mid=(l+r)>>1;
	if (mid==x) return;
	s.push_back(mid);
	if (x<mid) thief(l,mid-1,x);
	else thief(mid+1,r,x);
}
int c[A];
void update(int x,int y){
	for (; x<=1000000; x+=x&-x) c[x]+=y;
}
int ask(int x){
	int ret=0;
	for (; x; x^=x&-x) ret+=c[x];
	return ret;
}
int main(){
	int t; scanf("%d",&t);
	while (t--){
		int n,q; scanf("%d%d",&n,&q);
		p.clear();
		for (int i=1; i<=n; ++i) scanf("%d",&a[i]),p[a[i]]=1;
		int sz=0; for (map<int,int>::iterator i=p.begin(); i!=p.end(); ++i){
			i->second=++sz;
			// printf("%d\n",i->first);
		}
		for (int i=1; i<=n; ++i) a[i]=p[a[i]],update(a[i],1),w[a[i]]=i;
		while (q--){
			int x; scanf("%d",&x);
			x=w[p[x]];
			// cerr<<"p"<<x<<endl;
			s.clear();
			thief(1,n,x);
			int needbig=0,needsmall=0,ans=0,cms=0,cmb=0;
			for (vector<int>::iterator i=s.begin(); i!=s.end(); ++i){
				// cerr<<*i<<endl;
				if ((*i)<x&&a[*i]>a[x]) ++needsmall;
				else if ((*i)>x&&a[*i]<a[x]) ++needbig;
				else if (a[*i]<a[x]) ++cms;
				else ++cmb;
			}
			if (needbig>needsmall){
				// needbig-=needsmall;
				// ans+=needsmall;
				if (ask(1000000)-ask(a[x])-cmb<needbig) ans=-1; else ans+=needbig;
			}
			else if (needbig<needsmall){
				// needsmall-=needbig;
				// ans+=needbig;
				if (ask(a[x]-1)-cms<needsmall) ans=-1; else ans+=needsmall;
			}
			else ans=needsmall;
			printf("%d\n",ans);
			// system("pause");
		}
		for (int i=1; i<=n; ++i) update(a[i],-1);
	}
} 