#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    int lastNum = -1;
    for (int i : arr) {
        if (i != lastNum) {
            answer.push_back(i);
        }
        lastNum = i;
    }

    return answer;
}