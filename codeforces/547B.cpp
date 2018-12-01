#include <bits/stdc++.h>
using namespace std;
array<int, 200005> a;
array<int, 200005> L;
array<int, 200005> R;
array<int, 200005> ans;

int main()
{
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	stack<int> left;
	for (int i = 0; i < n; ++i)
	{
		while(!left.empty() && a[i] <= a[left.top()])
			left.pop();

		if(!left.empty())
			L[i] = left.top();
		else
			L[i] = -1;

		left.push(i);
	}
	stack<int> right;
	for (int i = n-1; i >= 0; --i)
	{
		while(!right.empty() && a[i] <= a[right.top()])
			right.pop();

		if(!right.empty())
			R[i] = right.top();
		else
			R[i] = n;
		right.push(i);
	}

	for (int i = 0,size; i < n; ++i)
	{
		size = R[i] - L[i] - 1;
		if(a[i] > ans[size])
			ans[size] = a[i];
	}

	for (int i = n; i > 0; --i)
		ans[i] = max(ans[i], ans[i+1]);
	for (int i = 1; i <= n; ++i)
		cout<<ans[i]<<' ';

	cout<<'\n';
	return 0;
}