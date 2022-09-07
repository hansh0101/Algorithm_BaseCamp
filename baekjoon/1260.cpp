#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int n,m,v;
vector<int> vec[1001];
bool visit[1001];
queue<int> q;

void dfs(int s) {
    int cur = s;
    cout<<cur<<" ";

    for(int nxt : vec[cur]) {
        if(!visit[nxt]) {
            visit[nxt] = true;
            dfs(nxt);
        }
    }

    for(int i=0; i<vec[cur].size(); i++) {
        if(!visit[vec[cur][i]]) {
            visit[vec[cur][i]] = true;
            dfs(vec[cur][i]);
        }
    }
}

void bfs() {
    while(!q.empty()) {
        int cur = q.front();
        cout<<cur<<" ";
        q.pop();

        for(int nxt : vec[cur]) {
            if(!visit[nxt]) {
                q.push(nxt);
                visit[nxt] = true;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>m>>v;
    for(int i=0;i<m;i++) {
        int s = 0, e = 0;
        cin>>s>>e;
        vec[s].push_back(e);
        vec[e].push_back(s);
    }

    for(auto & i : vec) {
        sort(i.begin(), i.end());
    }

    for(int i=1;i<=n;i++) {
        sort(vec[i].begin(), vec[i].end());
    }

    visit[v] = true;
    dfs(v);
    memset(visit, false, sizeof(visit));
    cout<<"\n";

    q.push(v);
    visit[v] = true;
    bfs();

    return 0;
}