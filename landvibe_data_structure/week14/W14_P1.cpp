#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> graph[101];
bool visit[101];

void dfs(int v) {
    cout << v << " ";

    for (int i = 0; i < graph[v].size(); i++) {
        if (!visit[graph[v][i]]) {
            visit[graph[v][i]] = true;
            dfs(graph[v][i]);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        for (int i = 0; i < 101; i++) {
            graph[i].clear();
        }
//        memset(visit, false, sizeof(visit));
        for(int i=0; i<101; i++) {
            visit[i] = false;
        }

        int n, m;
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            int s, d;
            cin >> s >> d;

            graph[s].push_back(d);
            graph[d].push_back(s);
        }

        visit[1] = true;
        dfs(1);
        cout << "\n";
    }
}