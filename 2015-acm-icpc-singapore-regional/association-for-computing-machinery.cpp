#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main()
{
    int len;
    cin >> len;

    vector<int> problems;

    int startIndex;
    cin >> startIndex;

    for (int i = 0; i < len; i++) {
        int qLength;
        cin >> qLength;
        problems.push_back(qLength);
    }

    int solvable = 0;
    int penTime = 0;
    int accumTime = 0;

    if (problems.at(startIndex) <= 300) {
        solvable++;
        penTime = problems.at(startIndex);
        accumTime = penTime;

        problems.erase(problems.begin() + startIndex);

        sort(problems.begin(), problems.end());

        for (int i = 0; i < len - 1; i++) {
            if (accumTime + problems.at(i) <= 300) {
                solvable++;
                penTime += penTime + problems.at(i);
                accumTime += problems.at(i);
            } else {
                break;
            }
        }
    }

    cout << solvable << " " << penTime;
}
