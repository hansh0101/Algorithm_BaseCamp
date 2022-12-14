#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> vec[1001];
bool visit[1001];
queue<int> q;
int ans;

void bfs(int start) {
    if(visit[start]) {
        return;
    }

    ans++;
    q.push(start);
    visit[start] = true;

    while(!q.empty()) {
        int cur = q.front();
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

    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int s = 0, e = 0;
        cin>>s>>e;
        vec[s].push_back(e);
        vec[e].push_back(s);
    }

    for(int i=1;i<=n;i++) {
        bfs(i);
    }

    cout<<ans;
    return 0;
}