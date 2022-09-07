#include <iostream>
#include <queue>

using namespace std;

int n, k;
bool visit[100001];
queue<pair<int, int>> q;

void bfs() {
    q.push({n, 0});
    visit[n] = true;

    while(!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cur == k) {
            cout<<cnt;
            break;
        }

        if(cur-1 >=0 && !visit[cur-1]) {
            q.push({cur-1, cnt+1});
            visit[cur-1] = true;
        }
        if(cur+1<=100000 && !visit[cur+1]) {
            q.push({cur+1, cnt+1});
            visit[cur+1] = true;
        }
        if(cur*2 <= 100000 && !visit[cur*2]) {
            q.push({cur*2, cnt+1});
            visit[cur*2] = true;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    bfs();

    return 0;
}