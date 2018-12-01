#include <bits/stdc++.h>
using namespace std;
#define FAST_IO 		ios::sync_with_stdio(false);cin.tie(0);
#define sz(a)			ll(a.size()) 
#define dbg(x)       	{ cerr << #x << " = " << x << endl; }

int main()
{
	FAST_IO
	vector <vector<vector <char>>> block(5, vector <vector <char>>(5, vector <char>(3)));
	block[0] = {
		{'*','*','*'},
		{'*','.','*'},
		{'*','*','*'},
		{'*','.','*'},
		{'*','.','*'}
	};
	block[1] = {
		{'*','*','*'},
		{'*','.','*'},
		{'*','*','*'},
		{'*','.','*'},
		{'*','*','*'}
	};
	block[2] = {
		{'*','*','*'},
		{'*','.','.'},
		{'*','.','.'},
		{'*','.','.'},
		{'*','*','*'}
	};
	block[3] = {
		{'*','*','*'},
		{'*','.','*'},
		{'*','.','*'},
		{'*','.','*'},
		{'*','*','*'}
	};
	block[4] = {
		{'*','*','*'},
		{'*','.','.'},
		{'*','*','*'},
		{'*','.','.'},
		{'*','*','*'}
	};
	int n;
	cin >> n;
	string s;
	cin>>s;
	vector <vector<char>> o(5, vector<char>(3*n));
	for (int i = 0; i < s.length(); ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				o[j][(3*i)+k] = block[s[i]-'A'][j][k];
			}
		}
	}
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 3*n; ++j)
		{
			cout << o[i][j];
		}
		cout << '\n';
	}
	return 0;
}