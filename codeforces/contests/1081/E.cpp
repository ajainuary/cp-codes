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

array <pair<int, int>, 200005> d;
int main() {
	FAST_IO
	for (int i = 1; i < 449; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			d[(i*i)-(j*j)] = {i,j};
		}
	}
	int n;
	cin >> n;
	vector <int> x(n);
	for (int i = 0; i < (n>>1); ++i)
	{
		cin >> x[i];
	}
	for (int i = 0,sum=0; i < n; ++i)
	{
		if(d[i+1].first == 0)
		{
			cout << "No\n";
			return 0;
		}
		else
		{

		}
	}
	return 0;
}