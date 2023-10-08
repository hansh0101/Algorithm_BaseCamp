#include <string>
#include <vector>
#include <cmath>

#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;

    bool isPrime[1000001];

    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }

    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= (int)sqrt(n); i++) {
        int num = i;

        if (isPrime[num] == false) {
            continue;
        }

        while (true) {
            num += i;
            if (num > n) {
                break;
            }
            isPrime[num] = false;
        }
    }

    for (int i = 0; i <= n; i++) {
        if (isPrime[i]) {
            answer++;
        }
    }

    return answer;
}