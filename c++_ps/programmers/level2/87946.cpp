#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    sort(dungeons.begin(), dungeons.end());

    do {
        int pow = k;
        int cnt = 0;
        for (int i = 0; i < dungeons.size(); i++) {
            if (pow >= dungeons[i][0]) {
                pow -= dungeons[i][1];
                cnt++;
            } else {
                break;
            }
        }

        answer = max(answer, cnt);
    } while (next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}