#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << std::endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
	}
#else
#define debug(...)
#endif
#define trace(c,x) for(auto &x:c)
int main() {
	FAST_IO
	int n;
	cin >> n;
	vector <pair<int, int>> freq(n, {0,-1});
	vector <int> b(n);
	for (int i = 0,a,d=1; i < n; ++i)
	{
		cin >> a;
		if(freq[a].first != 0)
		{
			b[i] = freq[a].second;
			freq[a].first--;
		}
		else
		{
			freq[a].first = n-a-1;
			b[i] = d;
			freq[a].second = d++;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if(freq[i].first != 0)
		{
			cout << "Impossible\n";
			return 0;
		}
	}
	cout << "Possible\n";
	for (int i = 0; i < n; ++i)
	{
		cout << b[i] << ' ';
	}
	cout << endl;
	return 0;
}