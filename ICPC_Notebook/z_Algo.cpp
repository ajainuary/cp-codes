#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);

void z_algo(vector <int> &z, string &s)
{
  //z[i] = length of the longest substring starting from the ith character,
  //       which is also a prefix of the same substring.
  int n = s.length();
  for(int i = 1, l = 0, r = 0; i < n; ++i) {
    if(i <= r) z[i] = min(z[i-l], r-i+1);
    while(i+z[i] < n && s[z[i]] == s[z[i]+i]) ++z[i];
    if(i+z[i]-1>r) l=i, r = i + z[i] - 1;
  }
  return;
}

int main() {
  FAST_IO
  
  return 0;
}