#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int> > maps) {
    int answer = -1;

    int n = maps.size();
    int m = maps[0].size();
    int mr[4] = {1, 0, -1, 0};
    int mc[4] = {0, 1, 0, -1};
    bool visited[100][100] = {false, };
    
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    visited[0][0] = true;

    while (!q.empty()) {
        pair<pair<int, int>, int> p = q.front();
        q.pop();

        int curr = p.first.first;
        int curc = p.first.second;
        int curcnt = p.second;

        if (curr == n - 1 && curc == m - 1) {
            answer = curcnt;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr + mr[i];
            int nc = curc + mc[i];
            int ncnt = curcnt + 1;

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }

            if (maps[nr][nc] == 1 && !visited[nr][nc]) {
                q.push({{nr, nc}, ncnt});
                visited[nr][nc] = true;
            }
        }
    }

    return answer;
}