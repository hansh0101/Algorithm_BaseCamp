#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int left = 0, right = people.size() - 1;
    
    while (left < right) {
        int rest = limit;
        
        rest -= people[left];
        
        if (rest - people[right] < 0) {
            answer++;
            right--;
        } else {
            answer++;
            left++;
            right--;
        }
    }
    
    if (left == right) {
        answer++;
    }
    
    return answer;
}