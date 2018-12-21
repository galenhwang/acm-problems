#include <bits/stdc++.h>

using namespace std;

void primeFactors(int n) {
    unordered_map<int, int> primeCounts;

    while (n%2 == 0) {
        if (!primeCounts[2]) {
            primeCounts[2] = 1;
        }
        primeCounts[2]++;
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i+2) {
        while (n%i == 0) {
            if (!primeCounts[i]) {
                primeCounts[i] = 1;
            }
            primeCounts[i]++;
            n = n/i;
        }
    }

    if (n > 2) {
        if (!primeCounts[n]) {
            primeCounts[n] = 1;
        }
        primeCounts[n]++;
    }

    int totalFactors = primeCounts.begin()->second;
    for (auto val = next(primeCounts.begin()); val != primeCounts.end(); ++val) {
        totalFactors *= val->second;
    }
    totalFactors -= primeCounts.size();
    cout << totalFactors << endl;
}

int main() {
    int len;
    cin >> len;

    for (int i = 0; i < len; i++) {
        int x;
        cin >> x;
        primeFactors(x);
    }

}
