#include <iostream>
#define pii pair<int, int>

using namespace std;

int n;
char arr[1002][1002];
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    // 1. 심장의 위치 찾기
    pii heart;
    for (int i = 1; i<= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] != '*') {
                continue;
            }

            bool isHeart = true;
            for (int k = 0; k < 4; k++) {
                if (arr[i + mx[k]][j + my[k]] != '*') {
                    isHeart = false;
                    break;
                }
            }

            if (isHeart) {
                heart = {j, i};
            }
        }
    }

    cout << heart.second << " " << heart.first << "\n";

    // 2. 왼팔 길이 구하기
    pii cur = heart;
    int leftHandLength = -1;
    while (arr[cur.second][cur.first] == '*') {
        leftHandLength++;
        cur.first--;
    }

    cout << leftHandLength << " ";

    // 3. 오른팔 길이 구하기
    cur = heart;
    int rightHandLength = -1;
    while (arr[cur.second][cur.first] == '*') {
        rightHandLength++;
        cur.first++;
    }

    cout << rightHandLength << " ";

    // 4. 허리 길이 구하기
    cur = heart;
    int middleLength = -1;
    while (arr[cur.second][cur.first] == '*') {
        middleLength++;
        cur.second++;
    }

    cout << middleLength << " ";

    // 5. 왼쪽 다리 길이 구하기
    pii standard = cur;
    int leftLegLength = 0;
    cur = {standard.first - 1, standard.second};
    while (arr[cur.second][cur.first] == '*') {
        leftLegLength++;
        cur.second++;
    }

    cout << leftLegLength << " ";

    // 6. 오른쪽 다리 길이 구하기
    int rightLegLength = 0;
    cur = {standard.first + 1, standard.second};
    while (arr[cur.second][cur.first] == '*') {
        rightLegLength++;
        cur.second++;
    }

    cout << rightLegLength << "\n";

    return 0;
}