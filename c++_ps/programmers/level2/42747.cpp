#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    int counts[10001] = {0, };

    for (int citation : citations) {
        for (int i = 0; i <= citation; i++) {
            counts[i]++;
        }
    }

    for (int i = 10000; i >= 0; i--) {
        if (i <= counts[i]) {
            answer = i;
            break;
        }
    }

    return answer;
}