#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, h, w;
  cin >> n >> h >> w;
  vector<int> x(n);
  for(int i=i;i<n;i++) {
    cin>>x[i];
  }

  int ans=0;
  for(int i=0;i<n;i+=2){
    ans += h * (min(x[i], w - x[i + 1]) + min(w - x[i], x[i + 1]));
  }
  cout<< ans << endl;
  return 0;
}
