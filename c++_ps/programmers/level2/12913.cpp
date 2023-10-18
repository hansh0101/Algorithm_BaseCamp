#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int solution(vector<vector<int>> land) {
    int answer = 0;

    int memo[100000][4];
    memset(memo, 0, sizeof(memo));
    for (int i = 0; i < 4; i++) {
        memo[0][i] = land[0][i];
    }

    for (int i = 1; i < land.size(); i++)  {
        for (int j = 0; j < 4; j++) {
            int maxValue = 0;
            for (int k = 0; k < 4; k++) {
                if (j == k) {
                    continue;
                }

                maxValue = max(maxValue, memo[i - 1][k]);
            }
            memo[i][j] = maxValue + land[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        answer = max(answer, memo[land.size() - 1][i]);
    }

    return answer;
}