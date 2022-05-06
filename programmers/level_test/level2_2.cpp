#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(int n) {
    string answer = "";

    int count = 0;
    while (n > 0) {
        count++;
        int num;
        if(count == 1) {
            num = n % (int)(pow(3, count));
        } else {
            int tmpN = n - 1;
            num = tmpN / (int)(pow(3, count - 1));
        }
        num = num % 3;
        answer.insert(answer.begin(), (char)('0' + num));
        n = n - pow(3, count);
    }

    for(int i=0; i<answer.size() - 1; i++) {
        if(answer[i] == '0') {
            answer[i] = '1';
        } else if(answer[i] == '1') {
            answer[i] = '2';
        } else if(answer[i] == '2') {
            answer[i] = '4';
        }
    }
    if(answer[answer.size() - 1] == '0') {
        answer[answer.size() - 1] = '4';
    }

    return answer;
}