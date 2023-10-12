#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct Process {
    int pid;
    int priority;

    Process(int pid, int priority) {
        this->pid = pid;
        this->priority = priority;
    }
};

int solution(vector<int> priorities, int location) {
    int answer = 0;

    deque<Process> vec;
    for (int i = 0; i < priorities.size(); i++) {
        vec.push_back(Process(i, priorities[i]));
    }
    
    sort(priorities.begin(), priorities.end(), greater<int>());
    
    while (true) {
        Process p = vec.front();
        vec.pop_front();

        if (priorities[answer] != p.priority) {
            vec.push_back(p);
        } else {
            answer++;
            if (p.pid == location) {
                break;
            }
        }
    }

    return answer;
}