#include <string>
#include <vector>

#define INF 1e9

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;

    int alpMax = alp;
    int copMax = cop;
    for (vector<int> v: problems) {
        alpMax = v[0] > alpMax ? v[0] : alpMax;
        copMax = v[1] > copMax ? v[1] : copMax;
    }

    vector<vector<int>> dp(alpMax + 1, vector<int>(copMax + 1, INF));
    dp[alp][cop] = 0;

    for (int i = alp; i <= alpMax; i++) {
        for (int j = cop; j <= copMax; j++) {
            if (i < alpMax) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            }
            if (j < copMax) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            }
            for (vector<int> v: problems) {
                if (i < v[0] || j < v[1]) {
                    continue;
                }
                int nextAlp = min(alpMax, i + v[2]);
                int nextCop = min(copMax, j + v[3]);
                dp[nextAlp][nextCop] = min(dp[nextAlp][nextCop], dp[i][j] + v[4]);
            }
        }
    }
    answer = dp[alpMax][copMax];

    return answer;
}