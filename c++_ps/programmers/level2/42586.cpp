#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<>> pq;
bool finished[101];
int nxt = 1;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    while (nxt - 1 != progresses.size()) {
        for (int i = 0; i < progresses.size(); i++) {
            if (finished[i]) continue;

            progresses[i] += speeds[i];
            if (progresses[i] >= 100) {
                finished[i] = true;
                pq.push(i + 1);
            }
        }

        int count = 0;
        while (true) {
            if (!pq.empty() && pq.top() == nxt) {
                nxt = pq.top() + 1;
                pq.pop();
                count++;
            } else {
                break;
            }
        }

        if (count != 0) {
            answer.push_back(count);
        }
    }

    return answer;
}