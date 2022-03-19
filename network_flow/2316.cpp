#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 801
#define INF 1e9
using namespace std;

int ans, maxflow;
int n, p;
int u, v;
vector<int> vec[MAX];
int cap[MAX][MAX];
int flow[MAX][MAX];
int prevnode[MAX];

bool bfs() {
    memset(prevnode, 0, sizeof(prevnode));
    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if(cur == 2) {
            return true;
        }

        for(int i=0;i<vec[cur].size();i++) {
            int nxt = vec[cur][i];

            if(prevnode[nxt] == 0 && cap[cur][nxt] - flow[cur][nxt] > 0) {
                prevnode[nxt] = cur;
                q.push(nxt);
            }
        }
    }
    return false;
}

void max_flow() {
    while(true) {
        if(!bfs()) {
            break;
        }

        maxflow = INF;
        for(int i=2;i!=1;i=prevnode[i]) {
            maxflow = min(maxflow, cap[prevnode[i]][i] - flow[prevnode[i]][i]);
        }

        for(int i=2;i!=1;i=prevnode[i]) {
            flow[prevnode[i]][i] += maxflow;
            flow[i][prevnode[i]] -= maxflow;
        }
        ans++;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>p;
    for(int i=0;i<p;i++) {
        cin>>u>>v;
        // 입구 - 출구 연결
        vec[u].push_back(u+400);
        vec[u+400].push_back(u);
        vec[v].push_back(v+400);
        vec[v+400].push_back(v);
        cap[u][u+400] = 1;
        cap[v][v+400] = 1;
        // 정점 - 정점 연결
        vec[u+400].push_back(v);
        vec[v].push_back(u+400);
        vec[v+400].push_back(u);
        vec[u].push_back(v+400);
        cap[u+400][v] += 1;
        cap[v+400][u] += 1;
    }
    cap[1][401] = INF;
    cap[2][401] = INF;
    max_flow();
    cout<<ans;
    return 0;
}