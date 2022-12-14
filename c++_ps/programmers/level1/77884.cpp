#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++) {
        if (sqrt(i) - (int) (sqrt(i)) == 0) {
            answer -= i;
        } else {
            answer += i;
        }
    }

    return answer;
}