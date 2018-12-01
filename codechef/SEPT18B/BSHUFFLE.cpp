#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i = 2; i <= ((n+1)>>1); ++i)
		cout << i << ' ';
	cout << 1 << ' ';
	for (int i = ((n+1)>>1)+2; i <= n; ++i)
		cout << i << ' ';
	cout << ((n+1) >> 1) + 1<< '\n';
	cout << n << ' ';
	for (int i = 1; i < n; ++i)
		cout << i << ' ';
	cout << '\n';
	return 0;
}