#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    int arr[32];
    for (int i = 0; i < 32; i++) {
        if (i >= 1 && i <= n) {
            arr[i] = 1;
        } else {
            arr[i] = 0;
        }
    }

    for (int idx: lost) {
        arr[idx]--;
    }

    for (int idx: reserve) {
        arr[idx]++;
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i] == 2) {
            if (arr[i - 1] == 0 && i != 1) {
                arr[i - 1]++;
                arr[i]--;
            } else if (arr[i + 1] == 0 && i != n) {
                arr[i + 1]++;
                arr[i]--;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i] >= 1) {
            answer++;
        }
    }

    return answer;
}