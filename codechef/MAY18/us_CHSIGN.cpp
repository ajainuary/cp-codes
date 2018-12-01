#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector <int> A(n);
		for(int &x : A)
			cin>>x;

		for (vector<int>::iterator i = A.begin(); i != A.end(); ++i)
			if((*i < *(i-1) || i == A.begin()) && (*i < *(i+1) || i == A.end()-1))
				cout<<'-'<<*i<<' ';
			else
				cout<<*i<<' ';
	}
	return 0;
}