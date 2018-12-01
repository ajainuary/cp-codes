#include <bits/stdc++.h>
using namespace std;
//first: less than x
//second: more than x
pair<int, int> bs(int i, int low, int high, vector<int> &A, int x)
{
	int mid = (low + high)>>1;
 
	if(i == mid)
		return make_pair(0, 0);
	if(i < mid)
	{
		if(A[mid] > x)
			return bs(i, low, mid-1, A, x);
		else
		{
			auto res = bs(i, low, mid-1, A, x);
			res.second += 1;
			return res;
		}
	}
	else
	{
		if(A[mid] > x)
		{
			auto res = bs(i, mid+1, high, A, x);
			res.first += 1;
			return res;
		}
		else
			return bs(i, mid+1, high, A, x);
	}
}
 
// int srch(vector<int> S, int x)
// {
// 	int low = 0;
// 	int high = S.size() - 1;
// 	while(low <= high)
// 	{
// 		int mid = (low + high)>>1;
// 		if(S[mid] == x)
// 			return mid;
// 		else if(S[mid] < x)
// 			low = mid + 1;
// 		else
// 			high = mid - 1;
// 	}
// 	return -1;
// }
 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		vector <int> A(n);
		vector <int> sorted(n);
		unordered_map <int, int> indice;
		for (int i = 0; i < n; ++i)
		{
			cin>>A[i];
			indice[A[i]] = i;
			sorted[i] = A[i];
		}
		sort(sorted.begin(), sorted.end());
		for (int i = 0, X; i < q; ++i)
		{
			cin>>X;
			auto indice_X = indice.find(X);
			auto res = bs(indice_X->second, 0, n-1 , A, X);
			auto point = lower_bound(sorted.begin(), sorted.end(), X);
			int less = distance(sorted.begin(), point);
			int more = n - less - 1;
			if(less < res.first || more < res.second)
				cout<<"-1\n";
			else
				cout<<max(res.first, res.second)<<'\n';
		}
	}
	return 0;
} 