#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> s;

int solution(vector<int> elements) {
    int answer = 0;
    
    int sum = 0;
    for (int i : elements) {
        sum += i;
    }
    s.insert(sum);
    
    int windowSize = 1;
    while (windowSize <= elements.size() / 2) {
        int windowSum = 0;
        for (int i = 0; i <= windowSize - 1; i++) {
            windowSum += elements[i];
        }
        s.insert(windowSum);
        s.insert(sum - windowSum);
        
        for (int i = 1; i < elements.size(); i++) {
            windowSum = windowSum - elements[i - 1] + elements[(i + windowSize - 1) % elements.size()];
            s.insert(windowSum);
            s.insert(sum - windowSum);
        }
        
        windowSize++;
    }
    
    return s.size();
}