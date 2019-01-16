#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);

#define ll long long int
#define ld double
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define pll pair<ll, ll>
#define nl "\n"
#define debug(x) cerr << #x << " = " << x << nl;

typedef struct point {
  ld x, y;
} point;

typedef struct line {
  ld a, b, c;
  // of the form ax+by+c=0
} line;

line passing(point p, point b) {
  // line passing through 2 points
  return {b.y - p.y, p.x - b.x, (b.x - p.x) * p.y + (p.y - b.y) * p.x};
}

point meet(line p, line q) {
  // meeting point of 2 lines
  return {(p.b * q.c - q.b * p.c) / (p.a * q.b - q.a * p.b),
          (p.a * q.c - q.a * p.c) / (q.a * p.b - p.a * q.b)};
}

ld area_triangle(point a, point b, point c) {
  return abs((b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y)) / 2;
}

int main() {
  FAST_IO
  ld a1, b1, c1, a2, b2, c2;
  cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
  cout << area_triangle({a1, b1}, {c1, a2}, {b2, c2}) << endl;
  return 0;
}