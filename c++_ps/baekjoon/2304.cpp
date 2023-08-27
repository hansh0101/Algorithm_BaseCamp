#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pillar {
    int leftPosition;
    int height;

    Pillar(int leftPosition, int height) {
        this->leftPosition = leftPosition;
        this->height = height;
    }
};

int n, l, h;
vector<Pillar> pillars;
int result;

bool compare(Pillar p1, Pillar p2) {
    return p1.leftPosition < p2.leftPosition;
}

void getInput() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l >> h;
        pillars.push_back(Pillar(l, h));
    }
}

void solve() {
    // 기둥의 왼쪽 면의 위치가 정렬된 상태로 입력을 받는 것이 아니므로 정렬 수행
    sort(pillars.begin(), pillars.end(), compare);
    
    // 가장 높은 기둥의 인덱스 구하기
    int highestPillarIndex = -1;
    int highestPillarHeight = -1;
    for (int i = 0; i < pillars.size(); i++) {
        Pillar pillar = pillars[i];
        if (highestPillarHeight < pillar.height) {
            highestPillarHeight = pillar.height;
            highestPillarIndex = i;
        }
    }

    // 가장 높은 기둥의 왼쪽 부분 넓이 구하기
    int lastHighestPosition = pillars[0].leftPosition;
    int lastHighestHeight = pillars[0].height;
    for (int i = 1; i <= highestPillarIndex; i++) {
        Pillar pillar = pillars[i];

        if (i == highestPillarIndex) {
            result += lastHighestHeight * (pillars[highestPillarIndex].leftPosition - lastHighestPosition);
            break;
        }

        if (pillar.height > lastHighestHeight) {
            result += lastHighestHeight * (pillar.leftPosition - lastHighestPosition);
            lastHighestPosition = pillar.leftPosition;
            lastHighestHeight = pillar.height;
        }
    }

    // 가장 높은 기둥의 넓이 구하기
    result += highestPillarHeight;

    // 가장 높은 기둥의 오른쪽 부분 넓이 구하기
    lastHighestPosition = pillars[n - 1].leftPosition + 1;
    lastHighestHeight = pillars[n - 1].height;
    for (int i = pillars.size() - 2; i >= highestPillarIndex; i--) {
        Pillar pillar = pillars[i];

        if (i == highestPillarIndex) {
            result += lastHighestHeight * (lastHighestPosition - (pillars[highestPillarIndex].leftPosition + 1));
            break;
        }

        if (pillar.height > lastHighestHeight) {
            result += lastHighestHeight * (lastHighestPosition - (pillar.leftPosition + 1));
            lastHighestPosition = pillar.leftPosition + 1;
            lastHighestHeight = pillar.height;
        }
    }
}

void printResult() {
    cout << result << "\n";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    getInput();
    solve();
    printResult();
}