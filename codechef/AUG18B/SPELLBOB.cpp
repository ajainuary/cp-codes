#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<pair<char, char>> bob(3);
    for (auto &x : bob) cin >> x.first;
    for (auto &x : bob) cin >> x.second;
    int b=0,o=0,bo=0;
  	for (auto &x : bob)
  	{
  		if((x.first == 'b' && x.second == 'o') || (x.first == 'o' && x.second == 'b'))
  			++bo;
  		else if(x.first == 'b' || x.second == 'b')
  			++b;
  		else if(x.first == 'o' || x.second == 'o')
  			++o;
  	}
  	if(b > 1 && o > 0)
  		cout << "yes\n";
  	else if((b+bo > 1 && o > 0) || (o+bo > 0 && b > 1) || bo > 2 || (bo > 1 && b > 0))
  		cout << "yes\n";
  	else
  		cout << "no\n";
  }
  return 0;
}