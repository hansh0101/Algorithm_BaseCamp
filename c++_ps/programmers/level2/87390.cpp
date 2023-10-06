#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; i++) {
        int rowIndex = i / n + 1;
        int columnIndex = i % n + 1;

        answer.push_back(max(rowIndex, columnIndex));
    }

    return answer;
}