#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN 110

int used[MAXN][MAXN];
char str[MAXN][30];

int a1[MAXN],b1[MAXN], a2[MAXN], b2[MAXN];
int c[MAXN];

int q[600000];
int solved[MAXN];
int ans[MAXN];

vector<string> vec[MAXN];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, t;
	cin >> n >> t;
	for(int i = 0; i < n; ++i)
		cin >> a1[i] >> b1[i] >> a2[i] >> b2[i];
	int m;
	cin >> m;
	for(int i = 0; i < m; ++i) scanf("%s%d", str[i], c + i);
	int p = 0, l = 0, r = 0, rem = m, trem = t;
	for(int i = 0; i < m; ++i) q[r++] = i;
	while(rem) {
		int pro = q[l];
		int per = p, sum;
		if(per < n) sum = a1[per] + b2[per];
		else sum = a2[per - n] + b1[per - n];
		int need = max(1, c[pro] - sum - used[per % n][pro]);
		if(need <= trem) {
			solved[pro] = per % n;
			string temp(str[pro]);
			vec[per % n].push_back(temp);
			l++;
			trem -= need;
			--rem;
			++ans[per % n];
			if(trem == 0) {
				++p;
				if(p == 2 * n) p = 0;
				trem = t;
			}
		}
		else {
			used[per % n][pro] += trem;
			l++;
			q[r++] = pro;
			++p;
			if(p == 2 * n) p = 0;
			trem = t;
		}
	}
	for(int i = 0; i < n; ++i) {
		printf("%d", ans[i]);
		for(int j = 0; j < vec[i].size(); ++j) cout << " " << vec[i][j];
		puts("");
	}
	return 0;
}
