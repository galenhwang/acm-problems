#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int val;
        if (a % 2 == 0) val = 1;
        else val = 0;
        cout << val << endl;
    }
}
