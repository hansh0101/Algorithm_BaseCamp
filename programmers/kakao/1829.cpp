#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    queue<pair<int, int>> q;
    bool visit[100][100];
    memset(visit, false, sizeof(visit));
    int mr[4] = {0, -1, 0, 1};
    int mc[4] = {1, 0, -1, 0};

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(!visit[i][j] && picture[i][j] != 0) {
                number_of_area++;
                int tmp = 0;
                q.push({i, j});
                visit[i][j] = true;

                while(!q.empty()) {
                    int curr = q.front().first;
                    int curc = q.front().second;
                    q.pop();
                    tmp++;

                    for(int k=0; k<4; k++) {
                        int nr = curr + mr[k];
                        int nc = curc + mc[k];

                        if(nr < 0 || nc < 0 || nr > m -1 || nc > n - 1) {
                            continue;
                        }

                        if(!visit[nr][nc] && picture[curr][curc] == picture[nr][nc]) {
                            q.push({nr, nc});
                            visit[nr][nc] = true;
                        }
                    }
                }
                max_size_of_one_area = max(max_size_of_one_area, tmp);
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}