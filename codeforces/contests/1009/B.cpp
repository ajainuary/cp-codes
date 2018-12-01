#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define sz(a) ll(a.size())
#define dbg(x) \
  { cerr << #x << " = " << x << endl; }

bool cmp(char a, char b) {
  if (a == 0 && b == 1) return true;
  if (a == 1 && b == 0) return false;
  if (a == 1 && b == 2) return true;
  if (a == 2 && b == 1) return false;
  if (a == 0 && b == 2) return true;
  if (a == 2 && b == 0) return true;
  return false;
}

int main() {
  FAST_IO
  string s;
  cin >> s;
  vector <int> a(s.length());
  int one = 0;
  int zero = 0;
  int i = 0;
  while(i < s.length())
  {
  	if(s[i] == '2')
  		break;
  	if(s[i] == '1')
  		++one;
  	if(s[i] == '0')
  		++zero;
  	++i;
  }
  int j = i;
  while(j < s.length())
  {
  	if(s[j] == '1')
  		++one;
  	++j;
  }
  for (int k = 0; k < zero; ++k)
  {
  	cout << '0';
  }
  for (int k = 0; k < one; ++k)
  {
  	cout << '1';
  }
  for (int k = i; k < s.length(); ++k)
  {
  	if(s[k] != '1')
  		cout << s[k];
  }
  cout << endl;
  return 0;
}