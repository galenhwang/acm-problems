#include <bits/stdc++.h>

using namespace std;

bool sortByX(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.first < b.first);
}

float areaOfThreePoints(const pair<int, int> &a, const pair<int, int> &b, const pair<int, int> &c) {
    return abs(((a.first*(b.second-c.second)) +
                (b.first*(c.second-a.second)) +
                (c.first*(a.second-b.second)))/2);
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

    pair<int, int> A = points[0], B = points[1], C = points[2];
    int aIndex = 0;
    int bIndex = 1;
    int cIndex = 2;

    pair<int, int> bestA = A, bestB = B, bestC = C;

    while (true) {
        while (true) {
            while (areaOfThreePoints(A, B, C) <= areaOfThreePoints(A, B, points[(cIndex+1) % len])) {
                C = points[(cIndex+1) % len];
                cIndex = (cIndex + 1) % len;
            }
            if (areaOfThreePoints(A, B, C) <= areaOfThreePoints(A, points[(bIndex+1) % len], C)) {
                B = points[(bIndex+1) % len];
                bIndex = (bIndex+1) % len;
                continue;
            } else {
                break;
            }
        }

        if (areaOfThreePoints(A, B, C) > areaOfThreePoints(bestA,  bestB, bestC)) {
            bestA = A, bestB = B, bestC = C;
        }

        A = points[(aIndex+1) % len];
        aIndex = (aIndex+1) % len;

        if (A == B) {
            B = points[(bIndex+1) % len];
            bIndex = (bIndex+1) % len;
        }
        if (B == C) {
            C = points[(cIndex+1) % len];
            cIndex = (cIndex+1) % len;
        }
        if (aIndex == 0) {
            break;
        }
    }

    cout << areaOfThreePoints(bestA, bestB, bestC) << endl;
}
