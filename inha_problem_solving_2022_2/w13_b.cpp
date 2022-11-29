#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
#define pii pair<int, int>
using namespace std;

int t, n, m, q, u, v, w, uu, vv;
vector<pii> vec[250]; // first: cost, second: node index
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pii> startEndIndices; // first: start index, second: end index
int costs[250];
vector<int> results;

void init();
void input();
void solve();
void print();

void initCosts(int);
void dijkstra();

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
	for (int i = 0; i < 250; i++) {
		vec[i].clear();
	}
	while (!pq.empty()) {
		pq.pop();
	}
	startEndIndices.clear();
	results.clear();
}

void input() {
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		vec[u].push_back({ w, v });
		vec[v].push_back({ w, u });
	}
	for (int i = 0; i < q; i++) {
		cin >> uu >> vv;
		startEndIndices.push_back({ uu, vv });
	}
}

void solve() {
	for (int i = 0; i < startEndIndices.size(); i++) {
		int startIndex = startEndIndices[i].first;
		int endIndex = startEndIndices[i].second;
		initCosts(startIndex);
		pq.push({ 0, startIndex });
		dijkstra();

		results.push_back(costs[endIndex]);
	}
}

void print() {
	for (int result : results) {
		cout << result << "\n";
	}
}

void initCosts(int startIndex) {
	for (int i = 0; i < 250; i++) {
		costs[i] = INF;
	}
	costs[startIndex] = 0;
}

void dijkstra() {
	while (!pq.empty()) {
		pii curInfo = pq.top();
		int curCost = curInfo.first;
		int curIndex = curInfo.second;
		pq.pop();

		if (curCost > costs[curIndex]) {
			continue;
		}

		for (int i = 0; i < vec[curIndex].size(); i++) {
			pii nextInfo = vec[curIndex][i];
			int nextCost = curCost + nextInfo.first;
			int nextIndex = nextInfo.second;

			if (nextCost < costs[nextIndex]) {
				costs[nextIndex] = nextCost;
				pq.push({ nextCost, nextIndex });
			}
		}
	}
}

/*
2
4 4 4
0 2 20
2 3 10
1 2 30
3 0 5
0 3
2 3
1 2
0 2
5 7 5
0 4 100
1 4 20
2 0 3
2 1 17
4 2 50
2 3 40
1 3 10
4 2
1 2
2 0
4 1
0 3
*/