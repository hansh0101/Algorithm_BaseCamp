#include <vector>

using namespace std;

bool species[200001];

int solution(vector<int> nums) {
    int answer = 0;

    int speciesCount = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (!species[nums[i]]) {
            species[nums[i]] = true;
            speciesCount++;
        }
    }

    answer = speciesCount <= nums.size() / 2 ? speciesCount : nums.size() / 2;

    return answer;
}