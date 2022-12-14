#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(vector<vector<int>> flowers) {
    int answer = 0;

    bool days[366];
    memset(days, false, sizeof(days));

    for (vector<int> flower: flowers) {
        int startDay = flower[0];
        int endDay = flower[1];
        for (int i = startDay; i < endDay; i++) {
            days[i] = true;
        }
    }

    for (int i = 1; i <= 365; i++) {
        if (days[i]) {
            answer++;
        }
    }

    return answer;
}