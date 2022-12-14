#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1 = 0;
    long long sum2 = 0;
    queue<long long> q1;
    queue<long long> q2;

    for (int num: queue1) {
        sum1 += num;
        q1.push(num);
    }
    for (int num: queue2) {
        sum2 += num;
        q2.push(num);
    }

    while (sum1 != sum2) {
        if (answer > q1.size() + q2.size() + 1) {
            return -1;
        }

        if (sum1 < sum2) {
            q1.push(q2.front());
            sum1 += q2.front();
            sum2 -= q2.front();
            q2.pop();
        } else if (sum1 > sum2) {
            q2.push(q1.front());
            sum2 += q1.front();
            sum1 -= q1.front();
            q1.pop();
        }
        answer++;
    }

    return answer;
}