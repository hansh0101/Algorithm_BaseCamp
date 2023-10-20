#include <string>
#include <cstring>
#include <iostream>

#define U 0
#define D 2
#define R 1
#define L 3

using namespace std;

int toDir(char c) {
    if (c == 'U') {
        return U;
    } else if (c == 'D') {
        return D;
    } else if (c == 'R') {
        return R;
    } else if (c == 'L') {
        return L;
    }

    return -1;
}

int solution(string dirs) {
    int answer = 0;

    bool visited[11][11][4];
    memset(visited, false, sizeof(visited));

    int mr[4] = {-1, 0, 1, 0};
    int mc[4] = {0, 1, 0, -1};

    int curr = 5, curc = 5;
    for (int i = 0; i < dirs.length(); i++) {
        int dir = toDir(dirs[i]);
        int nr = curr + mr[dir];
        int nc = curc + mc[dir];

        if (nr < 0 || nc < 0 || nr > 10 || nc > 10) {
            continue;
        }

        if (!visited[nr][nc][dir] && !visited[curr][curc][(dir + 2) % 4]) {
            visited[nr][nc][dir] = true;
            visited[curr][curc][(dir + 2) % 4] = true;
            answer++;
        }

        curr = nr;
        curc = nc;
    }

    return answer;
}