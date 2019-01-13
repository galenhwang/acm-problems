#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string door;
    cin >> door;
    int rail;
    cin >> rail;
    if (door.at(0) == 'f') {
        if (rail == 1) cout << "L";
        else cout << "R";
    } else {
        if (rail == 1) cout << "R";
        else cout << "L";
    }
    return 0;
}
