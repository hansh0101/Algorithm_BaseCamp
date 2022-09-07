#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(int n) {
    string answer = "";

    int count = 1;
    do {
        int tmpN = n % (int) pow(3, count);
        if (tmpN == 0) tmpN = (int) pow(3, count);

        tmpN = (tmpN - 1) / (int) pow(3, count - 1);
        if (tmpN == 0) {
            answer.insert(0, "1");
        } else if (tmpN == 1) {
            answer.insert(0, "2");
        } else if (tmpN == 2) {
            answer.insert(0, "4");
        }
        n = n - (int) pow(3, count);
        count++;
    } while (n > 0);

    return answer;
}