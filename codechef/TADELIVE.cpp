#include <bits/stdc++.h>
using namespace std;

array <array <int, 5001>, 5001> cache; 

int Tip(int x, int y, vector <int> &A, vector <int> &B, int i)
{
	if(i < 0)
		return 0;
	if(cache[i][x] != 0)
		return cache[i][x];
	if(x > 0 && y > 0)
	{
		cache[i][x] = max(Tip(x-1, y, A, B, i-1) + A[i], Tip(x, y-1, A, B, i-1) + B[i]);
		return cache[i][x];
	}
	else if(x > 0)
	{
		cache[i][x] = Tip(x-1, y, A, B, i-1) + A[i];
		return cache[i][x];
	}
	else
	{
		cache[i][x] = Tip(x, y-1, A, B, i-1) + B[i];
		return cache[i][x];
	}
}

int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	vector <int> A(n);
	vector <int> B(n);
	for(int &x : A)
		cin>>x;
	for(int &x : B)
		cin>>x;
	cout << Tip(x, y, A, B, n-1) << endl;
	return 0;
}