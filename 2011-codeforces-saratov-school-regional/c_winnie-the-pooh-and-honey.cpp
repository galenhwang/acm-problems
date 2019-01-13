#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    int total = 0;
    for (int i = 0; i < n; i++) {
        int jar;
        cin >> jar;
        for (int j = 0; j < 3; j++) {
            if (jar >= k)
                jar -= k;
            else break;
        }
        total += jar;
    }
    cout << total;
}
