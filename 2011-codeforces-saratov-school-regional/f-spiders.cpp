#include <stdio.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void DFS(vector<int> graph[], int src, int prev_len, int *max_len, bool visited[]) {
    int curr_len = 0;
    visited[src] = true;

    for (int i = 0; i < graph[src].size(); i++) {
        int adjacent = graph[src][i];
        if (!visited[adjacent]) {
            curr_len = prev_len + 1;
            DFS(graph, adjacent, curr_len, max_len, visited);
        }
        if ((*max_len) < curr_len)
            *max_len = curr_len;
        curr_len = 0;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++) {
        int beads;
        cin >> beads;
        vector<int> graph[beads];
        for (int j = 0; j < beads-1; j++) {
            int from, to;
            cin >> from >> to;
            graph[from-1].push_back(to-1);
            graph[to-1].push_back(from-1);
        }
        int max = INT_MIN;
        for (int j = 0; j < beads-1; j++) {
            bool visited[beads] = {false};
            DFS(graph, j, 0, &max, visited);
        }
        total += max;
    }
    cout << total;
}
