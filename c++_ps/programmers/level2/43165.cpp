#include <string>
#include <vector>

using namespace std;

vector<bool> flag;
int answer = 0;

void check(vector<int> numbers, int target) {
    int result = 0;
    for (int i = 0; i < numbers.size(); i++) {
        result = flag[i] ? result + numbers[i] : result - numbers[i];
    }
    if (result == target) {
        answer++;
    }
}

void bt(vector<int> numbers, int size, int target) {
    if (size == numbers.size()) {
        check(numbers, target);
        return;
    }

    flag.push_back(true);
    bt(numbers, size + 1, target);
    flag.pop_back();

    flag.push_back(false);
    bt(numbers, size + 1, target);
    flag.pop_back();
}

int solution(vector<int> numbers, int target) {
    bt(numbers, 0, target);

    return answer;
}