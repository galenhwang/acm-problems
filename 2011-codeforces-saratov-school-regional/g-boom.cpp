#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_N 100

int used[MAX_N][MAX_N];
string str[MAX_N];

int a1[MAX_N],b1[MAX_N], a2[MAX_N], b2[MAX_N];
int c[MAX_N];

int q[600000];
int solved[MAX_N];
int ans[MAX_N];

vector<string> vec[MAX_N];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, t;
	cin >> n >> t;
	for (int i = 0; i < n; i++)
		cin >> a1[i] >> b1[i] >> a2[i] >> b2[i];
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> str[i] >> c[i];
	int p = 0, l = 0, r = m, rem = m, t_rem = t;
	for (int i = 0; i < m; i++)
		q[i] = i;
	while (rem) {
		int pro = q[l];
		int per = p;
		int sum;
		if (per < n)
			sum = a1[per] + b2[per];
		else
			sum = a2[per % n] + b1[per % n];
		int need = max(1, c[pro] - sum - used[per % n][pro]);
		if (need <= t_rem) {
			solved[pro] = per % n;
			vec[per % n].push_back(str[pro]);
			l++;
			t_rem -= need;
			rem--;
			ans[per % n]++;
			if(t_rem == 0) {
				p++;
				if(p == 2 * n)
					p = 0;
				t_rem = t;
			}
		}
		else {
			used[per % n][pro] += t_rem;
			l++;
			q[r++] = pro;
			p++;
			if (p == 2 * n)
				p = 0;
			t_rem = t;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i];
		for (int j = 0; j < vec[i].size(); j++)
		    cout << " " << vec[i][j];
		cout << endl;
	}
	return 0;
}
