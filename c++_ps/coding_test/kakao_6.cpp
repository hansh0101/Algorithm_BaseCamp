#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int mr[4] = {1, 0, 0, -1};
int mc[4] = {0, -1, 1, 0};
string dir[4] = {"d", "l", "r", "u"};

int n, m, x, y, r, c, k;
vector<string> answer;
bool flag;

void dfs(int curr, int curc, string str, bool visit[51][51]) {
    if (str.length() == k) {
        if (curr == r && curc == c) {
            answer.push_back(str);
        }
        flag = true;
        return;
    }

    if (curr == r && curc == c) {
        if ((k - str.length()) % 2 == 1) {
            flag = true;
            return;
        } else {
            int count = k - str.length();
            int halfCount = count / 2;

            vector<int> directionVector;

            int originCurr = curr;
            int originCurc = curc;
            while (halfCount != 0) {
                originCurr = curr;
                originCurc = curc;

                int direction = 0;
                if (curr + 1 <= n) direction = 0;
                else if (curc - 1 > 0) direction = 1;
                else if (curc + 1 <= m) direction = 2;
                else if (curr - 1 > 0) direction = 3;
                int oppositeDirection = 3 - direction;

                int howMuchCanIGo;
                if (direction == 0) {
                    howMuchCanIGo = n - curr;
                    curr += howMuchCanIGo;
                } else if (direction == 1) {
                    howMuchCanIGo = curc - 1;
                    curc -= howMuchCanIGo;
                } else if (direction == 2) {
                    howMuchCanIGo = m - curc;
                    curc += howMuchCanIGo;
                } else if (direction == 3) {
                    howMuchCanIGo = curr - 1;
                    curr -= howMuchCanIGo;
                }

                if (howMuchCanIGo > halfCount) howMuchCanIGo = halfCount;

                for (int i = 0; i < howMuchCanIGo; i++) {
                    directionVector.push_back(direction);
                }

                halfCount -= howMuchCanIGo;

                curr = originCurr;
                curc = originCurc;
            }

            for (int i = directionVector.size() - 1; i >= 0; i--) {
                int d = directionVector[i];
                directionVector.push_back(3 - d);
            }

            for (int i = 0; i < directionVector.size(); i++) {
                str += dir[directionVector[i]];
            }

            answer.push_back(str);
            flag = true;
            return;
        }
    }

    for (int i = 0; i < 4; i++) {
        int nr = curr + mr[i];
        int nc = curc + mc[i];

        if (nr <= 0 || nc <= 0 || nr > n || nc > m) continue;

        if (!visit[nr][nc]) {
            visit[nr][nc] = true;
            dfs(nr, nc, str + dir[i], visit);
            if (flag) return;
            visit[nr][nc] = false;
        }
    }
}

string solution(int nn, int mm, int xx, int yy, int rr, int cc, int kk) {
    n = nn, m = mm, x = xx, y = yy, r = rr, c = cc, k = kk;

    string a = "";

    bool visit[51][51];
    memset(visit, false, sizeof(visit));

    dfs(x, y, "", visit);

    if (answer.empty()) a = "impossible";
    else a = answer[0];

    return a;
}

//int main() {
//    solution(2, 2, 1, 1, 2, 2, 2);
//}