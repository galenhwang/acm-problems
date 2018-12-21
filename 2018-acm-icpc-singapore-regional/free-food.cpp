#include <bits/stdc++.h>

using namespace std;

bool sortByX(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.first < b.first);
}

int main()
{
    int len;
    cin >> len;

    vector<pair<int, int>> points;

    for (int i = 0; i < len; i++) {
        int x;
        int y;
        cin >> x;
        cin >> y;
        points.push_back(make_pair(x, y));
    }

    sort(points.begin(), points.end(), sortByX);

    int second = 0;

    int total = 0;

    for (int i = 0; i < points.size(); i++) {
        if (points[i].first > second) {
            total += points[i].second - points[i].first + 1;
            second = points[i].second;
        } else if (points[i].second > second) {
            total += points[i].second - second;
            second = points[i].second;
        }
    }

    cout << total << endl;
}
