#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cstring>

#define pii pair<int, int>
#define INF 1e9

using namespace std;

// 매우 중요 - 정점 번호가 1부터 시작하지만 나는 0부터 쓸거임
int solution(int n, vector<vector<int>> edges, vector<int> users, int d, int limit) {
    int answer = 0;

    // 그래프 만들기
    vector<pii > graph[n];
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        int dist = edges[i][2];

        graph[u].push_back({v, dist});
        graph[v].push_back({u, dist});
    }

    // 각 정점마다 접근 가능한 다른 정점들을 구하기
    set<int> accessAvailableNodes[n];
    for (int i = 0; i < n; i++) {
        priority_queue<pii, vector<pii >, greater<pii>> pq;
        vector<int> dist(n);
        for (int j = 0; j < n; j++) {
            dist[j] = INF;
        }
        dist[i] = 0;
        pq.push({0, i});

        while (!pq.empty()) {
            int curDist = pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            if (curDist > d) {
                break;
            }

            accessAvailableNodes[i].insert(cur);

            for (int j = 0; j < graph[cur].size(); j++) {
                int next = graph[cur][j].first;
                int nextDist = curDist + graph[cur][j].second;

                if (dist[next] > nextDist) {
                    dist[next] = nextDist;
                    pq.push({nextDist, next});
                }
            }
        }
    }

    // 2개의 파킹존 설치하기
    vector<int> vec(n, 0);
    vec[n - 1] = vec[n - 2] = 1;
    do {
        int f = -1, s = -1;
        int fSize = 0, sSize = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == 1) {
                if (f == -1) {
                    f = i;
                    continue;
                }
                s = i;
                break;
            }
        }

        set<int> duplicated;
        for (int i: accessAvailableNodes[f]) {
            if (accessAvailableNodes[s].find(i) == accessAvailableNodes[s].end()) {
                if (fSize + users[i] >= limit) {
                    fSize = limit;
                    break;
                } else {
                    fSize += users[i];
                }
            } else {
                duplicated.insert(i);
            }
        }

        for (int i: accessAvailableNodes[s]) {
            if (duplicated.find(i) == duplicated.end()) {
                if (sSize + users[i] >= limit) {
                    sSize = limit;
                    break;
                } else {
                    sSize += users[i];
                }
            }
        }

        if (fSize == limit && sSize == limit) {
            answer = limit * 2;
        } else {
            int sum = fSize + sSize;
            for (int i: duplicated) {
                if (sum + users[i] >= limit * 2) {
                    sum = limit * 2;
                    break;
                } else {
                    sum += users[i];
                }
            }
            answer = max(answer, sum);
        }
    } while (next_permutation(vec.begin(), vec.end()));

    return answer;
}

/*
 * 각 정점에 access가 가능한 정점들의 모임 accessAvailableNodes를 구한다.
 * 플로이드 와샬로 각 정점 간 최단거리를 모두 구해놓고 시작하는 게 좋을 것 같아보인다.(어차피 노드 간 거리 계산 다 해야되니까 ... ?)
 * vs
 * 플로이드 와샬로 하면 불필요하게 거리계산을 다 할 수도 있으니 다익스트라로 d를 넘기는 거리에 대해서는 계산을 안해버리는 것도 괜찮아보인다.
 * 2개의 파킹존 설치는 next_permutation을 활용한다.
 */