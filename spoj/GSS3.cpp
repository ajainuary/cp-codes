#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);

class Node {
 public:
  long long int left;
  long long int right;
  long long int max;
  long long int sum;
};

array<Node, 200005> tree;

void Build(vector<int> &A, int i, int l, int r) {
  if (l == r) {
    tree[i].left = A[l];
    tree[i].right = A[l];
    tree[i].max = A[l];
    tree[i].sum = A[l];
    return;
  }
  int mid = (l + r) >> 1;
  int left = (i << 1) | 1;
  int right = left + 1;
  Build(A, left, l, mid);
  Build(A, right, mid + 1, r);
  tree[i].left = max(tree[left].left, tree[left].sum + tree[right].left);
  tree[i].right = max(tree[right].right, tree[right].sum + tree[left].right);
  tree[i].max = max(tree[left].max,
                    max(tree[right].max, tree[left].right + tree[right].left));
  tree[i].sum = tree[left].sum + tree[right].sum;
  return;
}

Node Query(int s, int e, int i, int l, int r) {
  if (r < s || e < l) return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
  if (s <= l && r <= e) return tree[i];
  int mid = (l + r) >> 1;
  int left = (i << 1) | 1;
  int right = left + 1;
  auto leftNode = Query(s, e, left, l, mid);
  auto rightNode = Query(s, e, right, mid + 1, r);
  Node merge;
  merge.left = max(leftNode.left, leftNode.sum + rightNode.left);
  merge.right = max(rightNode.right, rightNode.sum + leftNode.right);
  merge.max =
      max(leftNode.max, max(rightNode.max, leftNode.right + rightNode.left));
  merge.sum = leftNode.sum + rightNode.sum;
  return merge;
}

void Update(int x, int y, int i, int l, int r) {
  if (x < l || r < x) return;
  if (l == r) {
    tree[i].left = y;
    tree[i].right = y;
    tree[i].max = y;
    tree[i].sum = y;
    return;
  }
  int mid = (l + r) >> 1;
  int left = (i << 1) | 1;
  int right = left + 1;
  Update(x, y, left, l, mid);
  Update(x, y, right, mid + 1, r);
  tree[i].left = max(tree[left].left, tree[left].sum + tree[right].left);
  tree[i].right = max(tree[right].right, tree[right].sum + tree[left].right);
  tree[i].max = max(tree[left].max,
                    max(tree[right].max, tree[left].right + tree[right].left));
  tree[i].sum = tree[left].sum + tree[right].sum;
  return;
}

int main() {
  FAST_IO
  int n;
  cin >> n;
  vector<int> A(n);
  for (int &x : A) cin >> x;
  Build(A, 0, 0, n - 1);
  int m;
  cin >> m;
  for (int i = 0, s, e, t; i < m; ++i) {
    cin >> t;
    if (t == 1) {
      cin >> s >> e;
      cout << Query(s - 1, e - 1, 0, 0, n - 1).max << '\n';
    } else {
      cin >> s >> e;
      Update(s - 1, e, 0, 0, n - 1);
    }
  }
  return 0;
}