#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> dpq;
    for(int i=0; i<operations.size(); i++) {
        string operation = operations[i];
        char oper = operation[0];
        string number = operation.substr(2, operation.size() - 2);
        int num;
        if(number[0] == '-') {
            num = (-1) * stoi(number.substr(1, number.size() - 1));
        } else {
            num = stoi(number);
        }

        if(oper == 'I') {
            dpq.push_back(num);
            sort(dpq.begin(), dpq.end());
        } else if(oper == 'D') {
            if(!dpq.empty()) {
                if (num == 1) {
                    dpq.erase(dpq.end() - 1);
                } else if(num == -1) {
                    dpq.erase(dpq.begin());
                }
            }
        }
    }

    if(dpq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(dpq[dpq.size()-1]);
        answer.push_back(dpq[0]);
    }

    return answer;;
}