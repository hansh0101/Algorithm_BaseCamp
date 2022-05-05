#include <string>
#define UP 1
#define DOWN 3
#define RIGHT 0
#define LEFT 2
using namespace std;

int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
bool visitPath[11][11][11][11];

int solution(string dirs) {
    int answer = 0;

    int curx = 5, cury = 5;
    for(int i=0; i<dirs.length(); i++) {
        char d = dirs[i];
        int dir = 0;

        if(d == 'U') {
            dir = UP;
        } else if(d == 'D') {
            dir = DOWN;
        } else if(d == 'R') {
            dir = RIGHT;
        } else if(d == 'L') {
            dir = LEFT;
        }

        int nx = curx + mx[dir];
        int ny = cury + my[dir];

        if(nx < 0 || ny < 0 || nx > 10 || ny > 10) {
            continue;
        }

        if(!visitPath[curx][cury][nx][ny] && !visitPath[curx][cury][nx][ny]) {
            answer++;
            visitPath[curx][cury][nx][ny] = true;
            visitPath[nx][ny][curx][cury] = true;
        }

        curx = nx;
        cury = ny;
    }

    return answer;
}