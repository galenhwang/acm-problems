#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, picked;
    cin >> n >> picked;
    int questions[n];
    for (int i = 0; i < n; i++) {
        cin >> questions[i];
    }
    for (int i = 0; i < n; i++) {
        int index = (i+picked-1) % n;
        if (questions[index] == 1) {
            cout << index+1;
            break;
        }
    }
}
