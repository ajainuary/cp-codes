#include <bits/stdc++.h>
using namespace std;

bool check_Volume(int U, int V, int W, int u, int v, int w) {
	//Check if the first 3 actually form a triangle
	if(U+V<=W || U+W<=V || V+W<=U || U-V>=W || U-W>=V || V-W>=U)
		return false;
  int X = (w - U + v) * (U + v + w);
  int x = (U - v + w) * (v - w + U);
  int Y = (u - V + w) * (V + w + u);
  int y = (V - w + u) * (w - u + V);
  int Z = (v - W + u) * (W + u + v);
  int z = (W - u + v) * (u - v + W);
  long double a2 = x * Y * Z;
  if (a2 < 0) return false;
  long double b2 = y * Z * X;
  if (b2 < 0) return false;
  long double c2 = z * X * Y;
  if (c2 < 0) return false;
  long double d2 = x * y * z;
  if (d2 < 0) return false;
  long double a = sqrt(a2);
  long double b = sqrt(b2);
  long double c = sqrt(c2);
  long double d = sqrt(d2);
  if((b + c + d - a) > 0 && (a - b + c + d)  > 0 && (a + b - c + d) > 0 && (a + b + c - d) > 0)
  {
  	cerr << (b + c + d - a) << ' ' << (a - b + c + d) << ' ' << (a + b - c + d) << ' ' << (a + b + c - d) << endl;
  	return true;
  }
  else
  	return false;
}

bool check(int e[]) {
  for (int i = 5; i > 1; --i)
    for (int j = i - 1; j > 0; --j)
      for (int k = j - 1; k >= 0; --k)
        for (int p = 0; p < 6; ++p)
          if (p != i && p != j && p != k)
            for (int q = 0; q < 6; ++q)
              if (q != p && q != i && q != j && q != k)
                for (int r = 0; r < 6; ++r)
                  if (r != p && r != q && r != i && r != j && r != k)
                    if (check_Volume(e[i], e[j], e[k], e[p], e[q], e[r]))
                    {
                    	cerr << e[i] << ' ' << e[j] << ' ' << e[k] << ' ' << e[p] << ' ' << e[q] << ' ' << e[r] << endl;
                      return true;
                    }
  return false;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int e[6];
    for (int i = 0; i < 6; ++i) cin >> e[i];
    if (check(e))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}