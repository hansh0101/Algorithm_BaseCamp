#include <string>
#include <vector>

using namespace std;

int countOf1(int n) {
    int count = 0;
    
    while (n != 0) {
        if (n % 2 == 1) {
            count++;
        }
        n /= 2;
    }
    
    return count;
}

int solution(int n) {
    int answer = 0;
    
    int count = countOf1(n);
    
    for (int i = n + 1; i <= 1000000; i++) {
        if (countOf1(i) == count) {
            answer = i;
            break;
        }
    }
    
    return answer;
}