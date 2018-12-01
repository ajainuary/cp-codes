#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector <int> A(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>A[i];
		}
		vector <int> left(n);
		vector <int> right(n);
		stack<int> s;
		for (int i = 0; i < n; ++i)
		{
			while(!s.empty() && A[i] > A[s.top()])
			{
				// dbg(s.top())
				s.pop();
			}
			left[i] = (s.empty()) ? -1 : s.top();
			s.push(i);
		}
		stack<int> t;
		for (int i = n-1; i >= 0; --i)
		{
			while(!t.empty() && A[i] > A[t.top()])
				t.pop();
			right[i] = (t.empty()) ? -1 : t.top();
			t.push(i);
		}

		for (int i = 0; i < n; ++i)
		{
			if(left[i] == -1 || right[i] == -1)
				cout<<"0 ";
			else
				cout<<right[i] - left[i] - 1<<' ';
		}
		cout<<'\n';
	}
	return 0;
}