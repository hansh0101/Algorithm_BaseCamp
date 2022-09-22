#include <string>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (vector<int> path: paths) {
        int from = path[0];
        int to = path[1];
        int weight = path[2];

        bool isFromGate = false;
        bool isFromSummit = false;
        bool isToGate = false;
        bool isToSummit = false;

        for (int gate: gates) {
            if (gate == from) isFromGate = true;
            else if (gate == to) isToGate = true;
        }
        for (int summit: summits) {
            if (summit == from) isFromSummit = true;
            else if (summit == to) isToSummit = true;
        }

        if (isFromGate || isToSummit) {
            graph[from].push_back({to, weight});
        } else if (isToGate || isFromSummit) {
            graph[to].push_back({from, weight});
        } else {
            graph[from].push_back({to, weight});
            graph[to].push_back({from, weight});
        }
    }

    priority_queue<pair<int, int>> pq;
    vector<int> dist(n + 1, INF);
    for (int gate: gates) {
        pq.push({0, gate});
        dist[gate] = 0;
    }

    while (!pq.empty()) {
        int cur = pq.top().second;
        int curWeight = -pq.top().first;
        pq.pop();

        if (curWeight > dist[cur]) {
            continue;
        }
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nextWeight = max(graph[cur][i].second, curWeight);
            if (dist[next] > nextWeight) {
                dist[next] = nextWeight;
                pq.push({-nextWeight, next});
            }
        }
    }

    priority_queue<pair<int, int>> result;
    for (int summit: summits) {
        result.push({-dist[summit], -summit});
    }
    answer.push_back(-result.top().second);
    answer.push_back(-result.top().first);

    return answer;
}