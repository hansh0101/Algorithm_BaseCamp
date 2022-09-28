#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int t, n, m, u, v, p;
vector<vector<int>> vec(100001);
bool visit[100001];
int cnt[100001];
bool isPolluted[100001];

int dfs(int par, int cur) {
	int pCount = 0;
	if (isPolluted[cur]) pCount++;
	for (int i = 0; i < vec[cur].size(); i++) {
		int next = vec[cur][i];
		if (!visit[next]) {
			visit[next] = true;
			int dfsResult = dfs(cur, next);
			if (dfsResult == m) {
				return m;
			}
			else {
				pCount += dfsResult;
			}
		}
	}

	if (pCount == m) {
		if (cur == 1) {
			cout << "-1\n";
		}
		else {
			cout << min(cur, par) << " " << max(cur, par) << "\n";
		}
	}

	return pCount;
}

void init() {
	for (int i = 0; i < vec.size(); i++) vec[i].clear();
	memset(visit, false, sizeof(visit));
	memset(cnt, 0, sizeof(cnt));
	memset(isPolluted, false, sizeof(isPolluted));
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n >> m;

		init();
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		for (int i = 0; i < m; i++) {
			cin >> p;
			isPolluted[p] = true;
		}

		visit[1] = true;
		dfs(0, 1);
	}
}

/*
2
7 2
1 2
1 5
1 7
3 5
5 6
2 4
3 6
4 3
1 2
1 3
1 4
2 3 4
*/