#include <vector>
#include <cstring>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    int cnt = 0;
    bool check[200001];
    memset(check, false, sizeof(check));
    for(int i=0;i<nums.size();i++) {
        if(!check[nums[i]]) {
            check[nums[i]] = true;
            cnt++;
        }
    }

    if(cnt > nums.size() / 2) {
        answer = nums.size() / 2;
    } else {
        answer = cnt;
    }

    return answer;
}
