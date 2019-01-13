#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int get (int accumTotal[], int first, int last) {
    int permVal = accumTotal[last];
    if (first > 0)
        permVal -= accumTotal[first-1];
    return permVal;
}

int numWays(int len, int accumTotal[], int sons[]) {
    int val = 0;
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len - 1; j++) {
            int perm[3] = { get(accumTotal, 0, i),get(accumTotal, i+1,j),
                get(accumTotal, j+1,len-1) };
            sort(perm, perm+3);
            if(perm[0] == sons[0] && perm[1] == sons[1] && perm[2] == sons[2])
                val++;
        }
    }
    return val;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    int count = 0;
    int accumRowTotals[n];
    int accumColTotals[m];
    for (int i = 0; i < n; i++) {
        accumRowTotals[i] = 0;
        for (int j = 0; j < m; j++) {
            if (i == 0) accumColTotals[j] = 0;
            int val;
            cin >> val;
            accumRowTotals[i] += val;
            accumColTotals[j] += val;
        }
        if (i > 0) accumRowTotals[i] += accumRowTotals[i-1];
    }
    for (int j = 0; j < m; j++) {
        if (j > 0) accumColTotals[j] += accumColTotals[j-1];
    }
    int sons[3];
    for (int i = 0; i < 3; i++) {
        cin >> sons[i];
    }
    sort(sons, sons+3);
    cout << numWays(m, accumColTotals, sons) + numWays(n, accumRowTotals, sons) << endl;
}
