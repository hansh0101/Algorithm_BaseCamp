#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    stack<int> st[30];
    for (int i = board[0].size() - 1; i >= 0; i--) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] != 0) {
                st[j].push(board[i][j]);
            }
        }
    }

    stack<int> s;
    for (int i = 0; i < moves.size(); i++) {
        int m = moves[i] - 1;
        if (!st[m].empty()) {
            int n = st[m].top();
            st[m].pop();

            if (!s.empty()) {
                int nn = s.top();
                if (nn == n) {
                    answer += 2;
                    s.pop();
                } else {
                    s.push(n);
                }
            } else {
                s.push(n);
            }
        }
    }

    return answer;
}