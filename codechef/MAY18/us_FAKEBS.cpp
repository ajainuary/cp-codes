#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);

void mkTree(int i, int low, int high, vector<int> &tree, vector<int> &A, unordered_map<int, int> &indice)
{
	if(low > high)
		return;
	int mid = (low + high)>>1;
	tree[i] = A[mid];
	indice[A[mid]] = i;
	mkTree(i<<1, low, mid-1, tree, A, indice);
	mkTree((i<<1)|1, mid+1, high, tree, A, indice);
	return;
}

pair<pair<int, int>, pair<int, int>> bs(int i, int x, vector<int> &tree)
{
	int reqles = 0;
	int reqmor = 0;
	int less = 0;
	int more = 0;
	while(i>1)
	{
		int parent = i>>1;
		if((i&1) == 0)
			++reqmor;
		else
			++reqles;
		
		if((i&1) == 0 && tree[parent] < x)
			++more;
		if((i&1) == 1 && tree[parent] > x)
			++less;
		i = parent;
	}
	return make_pair(make_pair(reqles, reqmor), make_pair(more, less));
}

int main()
{
	FAST_IO
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		vector<int> A(n+1);
		vector<int> sorted(n);
		unordered_map<int, int> indice;
		for (int i = 1; i <= n; ++i)
		{
			cin>>A[i];
			sorted[i-1] = A[i];
			indice[A[i]] = i;
		}
		vector<int> tree((n+1)<<1);
		mkTree(1, 1, n, tree, A, indice);
		sort(sorted.begin(), sorted.end());
		for (int i = 0,x; i < q; ++i)
		{
			cin>>x;
			auto point = lower_bound(sorted.begin(), sorted.end(), x);
			int less = distance(sorted.begin(), point);
			int more = n - less - 1;
			auto res = bs(indice[x], x, tree);
			if(res.first.second > more || res.first.first > less)
				cout<<"-1\n";
			else
				cout<<max(res.second.first, res.second.second)<<'\n';
		}
	}
}