#include <vector>

using namespace std;

int answer = 0;
vector<int> numbers;

void check() {
    int tmp = 0;
    for (int i = 0; i < numbers.size(); i++) {
        tmp += numbers[i];
    }
    for (int i = 2; i < tmp; i++) {
        if (tmp % i == 0) {
            return;
        }
    }
    answer++;
}

void recursion(vector<int> nums, int size, int index) {
    if (size == 3) {
        check();
    } else if (index == nums.size()) {
        return;
    } else {
        numbers.push_back(nums[index]);
        recursion(nums, size + 1, index + 1);
        numbers.pop_back();
        recursion(nums, size, index + 1);
    }
}

int solution(vector<int> nums) {
    recursion(nums, 0, 0);
    return answer;
}