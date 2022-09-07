#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<>> pq;
    for (int i: scoville) {
        pq.push(i);
    }

    int count = 0;
    while (true) {
        if (pq.top() >= K) {
            answer = count;
            break;
        }

        if (pq.size() == 1) {
            answer = -1;
            break;
        }

        int x = pq.top();
        pq.pop();
        int y = pq.top() * 2;
        pq.pop();
        pq.push(x + y);
        count++;
    }

    return answer;
}