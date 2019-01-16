#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);

int main() {
  FAST_IO
  int n,m;
  cin >> n >> m;
  vector <pair <int, int>> A(n);
  vector <pair <int, int>> B(m);
  for (int i = 0; i < n; ++i)
  {
    cin >> A[i].first;
    A[i].second = i;
  }
  for (int i = 0; i < m; ++i)
  {
    cin >> B[i].first;
    B[i].second = i;
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int i=0,j=0,k=0;
  while(i < n && j < m) {
    cout << A[i].second << ' ' << B[j].second << '\n';
    if(k == 0)
      ++i;
    else
      ++j;
    k = 1-k;
  }
  if(j == m) ++i;
  else if(i == n) ++j;
  while(i < n)
    cout << A[i++].second << ' ' << B[m-1].second << '\n';
  while(j < m)
    cout << A[n-1].second << ' ' << B[j++].second << '\n';
  return 0;
}