#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX_N 200000

int a[10000000];
int b[10000000];
int testcases[MAX_N];

struct node {
    int x;
    int y;
} ans[MAX_N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> testcases[i];
  }
  int flag = true;
  for (int i = 0; i < n; i++) {
    int product = testcases[i];
    int k = false;
    if (b[product] > 0) {
        ans[i].x = b[product];
        ans[i].y = product / b[product];
        b[product] = 0;
        k = true;
    } else {
      while (true) {
        int val = ++a[product];
        if (val * val > product) {
            flag = false;
            break;
        }
        if (product % val == 0) {
          ans[i].x = val;
          ans[i].y = product / val;
          if (ans[i].x != ans[i].y)
              b[product] = product / val;
          k = true;
          break;
        }
      }
    }
    if (k == false)
      flag = false;
    if (flag == false)
      break;
  }
  if (flag == false)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      cout << ans[i].x << " " << ans[i].y << endl;
    }
  }
  return 0;
}
