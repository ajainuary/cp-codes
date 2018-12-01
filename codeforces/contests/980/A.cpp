#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int p=0,l=0;
	string s;
	cin>>s;
	for (int i = 0; i < s.length(); ++i)
		if(s[i] == 'o')
			++p;
		else
			++l;
	if(p == 0 || l % p == 0)
		cout << "YES\n";
	else
		cout<< "NO\n";
	return 0;
}