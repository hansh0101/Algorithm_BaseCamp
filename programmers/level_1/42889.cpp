#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check[501];

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<pair<double, int>> v;
    sort(stages.begin(), stages.end());
    for(int i = 0; i < stages.size();) {
        int curStage = stages[i];
        if(curStage == N+1) {
            break;
        }
        int nxtStage = curStage;
        int count = 0;
        do {
            count++;
            nxtStage = stages[i+count];
        } while(curStage == nxtStage);
        double fail = (double)count/(double)(stages.size() - i);
        v.push_back({-fail, curStage});
        i = i + count;
    }

    sort(v.begin(), v.end());

    for(auto i: v) {
        answer.push_back(i.second);
    }

    return answer;
}