#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int t, n, m, k;
int start;
vector<int> heights;
vector<int> graph[1000];
vector<int> towns;
queue<pair<int, int>> q;
bool visit[1000];
int result[1000];

void init();

void input();

void solve();

void print();

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

    return 0;
}

void init() {
    heights.clear();
    for (auto & i : graph) {
        i.clear();
    }
    towns.clear();
    memset(result, -1, sizeof(result));
    memset(visit, false, sizeof(visit));
}

void input() {
    cin >> n >> m >> k;

    int index = -1;
    long long minHeight = 1e9 + 1;
    for (int i = 0; i < n; i++) {
        long long height;
        cin >> height;
        if (height < minHeight) {
            minHeight = height;
            index = i;
        }
    }
    start = index;

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for (int i = 0; i < k; i++) {
        int town;
        cin >> town;
        towns.push_back(town);
    }
}

void solve() {
    q.push({start, 0});
    visit[start] = true;
    result[start] = 0;

    while (!q.empty())  {
        int cur = q.front().first;
        int curCost = q.front().second;
        q.pop();

        for (int next: graph[cur]) {
            if (!visit[next]) {
                q.push({next, curCost + 1});
                visit[next] = true;
                result[next] = curCost + 1;
            }
        }
    }
}

void print() {
    for (int town: towns) {
        cout << result[town] << "\n";
    }
}

/*
3
5 6 4
10 20 30 40 500001
0 4
1 4
2 0
2 1
4 2
2 3
4
3
0
15
6 7 3
52 125812 32 1 36 9999999
0 1
0 3
0 5
1 3
1 5
2 4
3 5
4
1
99
4 3 2
65 9 15 26
0 2
2 3
1 2
0
98
 */