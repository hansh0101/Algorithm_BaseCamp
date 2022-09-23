#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    int r = board.size();
    int c = board[0].size();
    vector<vector<int>> vec;
    vec.resize(r + 1, vector<int>(c + 1, 0));

    for (vector<int> v: skill) {
        int type = v[0];
        int r1 = v[1];
        int c1 = v[2];
        int r2 = v[3];
        int c2 = v[4];
        int degree = type == 1 ? -v[5] : v[5];

        vec[r1][c1] += degree;
        vec[r2+1][c1] -= degree;
        vec[r1][c2+1] -= degree;
        vec[r2+1][c2+1] += degree;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 1; j < c; j++) {
            vec[i][j] += vec[i][j - 1];
        }
    }

    for (int i = 0; i < c; i++) {
        for (int j = 1; j < r; j++) {
            vec[j][i] += vec[j - 1][i];
        }
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] + vec[i][j] >= 1) {
                answer++;
            }
        }
    }

    return answer;
}