#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    int l = 0, r = distance;
    sort(rocks.begin(), rocks.end());

    while (l <= r) {
        int m = (l + r) / 2;
        int prev = 0, cnt = 0;

        // 비교
        for (int i = 0; i < rocks.size(); i++) {
            if (rocks[i] - prev < m) {
                cnt++;
            } else {
                prev = rocks[i];
            }
        }
        if (distance - prev < m) {
            cnt++;
        }

        if (cnt <= n) {
            answer = max(m, answer);
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return answer;
}