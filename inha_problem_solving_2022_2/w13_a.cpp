#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int t, n, m, h, u, v;
vector<pii> vec[1000]; // first: height, second: node index
vector<int> heights(1000);
bool visit[1000];
vector<int> results;

void init();
void input();
void solve();
void print();

int getNextStartIndex();
void dfs(int);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		init();
		input();
		solve();
		print();
	}
}

void init() {
	for (int i = 0; i < 1000; i++) {
		vec[i].clear();
	}
	heights.clear();
	heights.resize(1000);
	memset(visit, false, sizeof(visit));
	results.clear();
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> heights[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		int uHeight = heights[u];
		int vHeight = heights[v];
		vec[u].push_back({ vHeight, v });
		vec[v].push_back({ uHeight, u });
	}
}

void solve() {
	while (true) {
		int startIndex = getNextStartIndex();
		if (startIndex == -1) {
			break;
		}

		visit[startIndex] = true;
		dfs(startIndex);
	}
}

void print() {
	for (int result : results) {
		cout << result << "\n";
	}
}

void dfs(int cur) {
	results.push_back(cur);

	vector<pii> linkedNodes;
	for (int i = 0; i < vec[cur].size(); i++) {
		pii nextInfo = vec[cur][i];
		int nextIndex = nextInfo.second;
		if (!visit[nextIndex]) {
			linkedNodes.push_back(nextInfo);
		}
	}

	sort(linkedNodes.begin(), linkedNodes.end());
	for (int i = 0; i < linkedNodes.size(); i++) {
		int nextIndex = linkedNodes[i].second;
		if (!visit[nextIndex]) {
			visit[nextIndex] = true;
			dfs(nextIndex);
		}
	}
}

int getNextStartIndex() {
	vector<pii> notVisitedNodes;
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			notVisitedNodes.push_back({heights[i], i});
		}
	}
	if (notVisitedNodes.empty()) {
		return -1;
	}
	sort(notVisitedNodes.begin(), notVisitedNodes.end());
	return notVisitedNodes[0].second;
}

/*
2
6 5
30 10050 456 25 70 63
0 2
4 5
2 1
3 5
4 3
5 5
30 10050 456 25 70
0 4
1 4
2 0
2 1
1 0
*/