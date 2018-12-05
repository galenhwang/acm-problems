#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

bool sortByUpper(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.second < b.second);
}

int main()
{
    int len;
    cin >> len;

    vector<pair<int, int>> pairs;

    for (int i = 0; i < len; i++) {
        int first;
        int second;
        cin >> first;
        cin >> second;
        pairs.push_back(make_pair(first, second));
    }

    sort(pairs.begin(), pairs.end(), sortByUpper);

    int rooms = 0;
    while (!pairs.empty()) {
        int temp = pairs.front().second;
        pairs.erase(pairs.begin());
        for (int i = 0; i < pairs.size();) {
            if (pairs[i].first <= temp && pairs[i].second >= temp) {
                pairs.erase(pairs.begin() + i);
            } else {
                i++;
            }
        }
        rooms++;
    }

    cout << rooms;
}
