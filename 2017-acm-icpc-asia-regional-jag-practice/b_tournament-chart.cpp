#include <bits/stdc++.h>
using namespace std;

string s;
int i = 0;
map<char, int> mp;

int read(){
    if (isalpha(s[i])) {
      return mp[s[i++]];
    }
    i++;
    int l = read();
    i++;
    int r = read();
    i++;
    if (max(l, r) > 0 && min(l, r) == 0) {
      return max(l, r) - 1;
    }
    return -1;
}

int main(){
    cin >> s;
    char c;
    int d;
    while (cin >> c >> d) {
      mp[c] = d;
    }
    if (read() != 0) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
}
