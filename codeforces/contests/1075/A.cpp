#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	unsigned long long int n;
	cin >> n;
	unsigned long long int x,y;
	cin >> x >> y;
	unsigned long long int move1 = min(x-1, y-1);
	move1 += x-1-move1+y-1-move1;
	unsigned long long int move2 = min(n-x,n-y);
	move2 += n-x-move2+n-y-move2;
	if(move1 <= move2)
		cout << "White\n";
	else
		cout << "Black\n";
	return 0;
}