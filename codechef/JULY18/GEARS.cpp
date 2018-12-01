#include <bits/stdc++.h>
using namespace std;

/* A Class for using fractions by Anurag Jain */
/*We require a gcd function for getting fractions in their minimal form*/
long long int gcd(long long int u, long long int v) {
  while (u != v && v != 0) {
    long long int tmp = v;
    v = u % v;
    u = tmp;
  }
  if (v == 0) return u;
  return v;
}
class fraction {
 public:
  long long int Nr;  // Numerator
  long long int Dr;  // Denominator
  fraction() {
    Nr = 0;
    Dr = 1;
  }
  fraction(long long int p,
           long long int q)  // When p & q are passed while initializing
  {
    Nr = p;
    Dr = q;
  }
  long long int numerator() { return Nr; }
  long long int denominator() { return Dr; }
  /* This is a special operator that brings the fraction to the minimal
   * form & negative to the numerator*/
  fraction& operator++() {
    long long int gcdnd = gcd(abs(Nr), abs(Dr));
    Nr /= gcdnd;
    Dr /= gcdnd;
    if (Dr < 0) {
      Nr = -Nr;
      Dr = abs(Dr);
    }
    return *this;
  }
};
/* Custom Operator Overloads */
fraction operator+(const fraction& x, const fraction& y) {
  fraction addition((x.Nr * y.Dr) + (y.Nr * x.Dr), x.Dr * y.Dr);
  return ++addition;
}
fraction operator-(const fraction& x, const fraction& y) {
  fraction subtraction((x.Nr * y.Dr) - (y.Nr * x.Dr), x.Dr * y.Dr);
  return ++subtraction;
}
fraction operator*(const fraction& x, const fraction& y) {
  fraction multiply((x.Nr * y.Nr), (x.Dr * y.Dr));
  return ++multiply;
}
fraction operator*(const fraction& x, const int no) {
  fraction multiply((x.Nr * no), x.Dr);
  return ++multiply;
}
fraction operator/(const fraction& x, const fraction& y) {
  fraction divide((x.Nr * y.Dr), (x.Dr * y.Nr));
  return ++divide;
}
/* Prints out the fraction (p/q) */
std::ostream& operator<<(std::ostream& os, fraction f) {
  return os << f.Nr << '\\' << f.Dr;
}
/* Custom comparators */
bool operator==(fraction x, fraction y) {
  ++x;
  ++y;
  return (x.Nr == y.Nr) && (x.Dr == y.Dr);
}
bool operator!=(fraction x, fraction y) {
  ++x;
  ++y;
  return !((x.Nr == y.Nr) && (x.Dr == y.Dr));
}

typedef struct GEAR {
  fraction speed;
  int x, y;
  int teeth;
} gear;

array<gear, 100005> a;
array<vector<int>, 100005> graph;

pair<int, int> DSU_find(vector<pair<int, int>>& DSU, int x) {
  if (DSU[x].first < 0) return {x, 0};
  auto tmp = DSU_find(DSU, DSU[x].first);
  tmp.second += DSU[x].second;
  DSU[x] = tmp;
  return DSU[x];
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> DSU(n + 1, {-1, 0});
  for (int i = 1; i <= n; ++i) cin >> a[i].teeth, a[i].speed = fraction();
  for (int i = 0, t; i < m; ++i) {
    cin >> t;
    if (t == 1) {
      int x, c;
      cin >> x >> c;
      a[x].teeth = c;
    } else if (t == 2) {
      int x, y;
      cin >> x >> y;
      graph[x].push_back(y);
      graph[y].push_back(x);
    } else if (t == 3) {
      int x, y, v;
      cin >> x >> y >> v;
      a[x].speed = fraction(v, 1);
    }
  }
  return 0;
}