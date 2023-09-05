#include <iostream>
#include <vector>

using namespace std;

int n, k;
int durabilities[201];
int loadIndex, unloadIndex;
vector<int> robotPositions;
bool isLoaded[201];
int result;

void getInput();
void solve();
void printResult();

void turnAround();
void moveRobot();
void loadRobot();
void unloadRobot();
bool checkState();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    getInput();
    solve();
    printResult();

    return 0;
}

void getInput() {
    cin >> n >> k;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> durabilities[i];
    }
}

void solve() {
    result = 0;
    loadIndex = 1;
    unloadIndex = n;

    while (true) {
        result++;

        turnAround();
        moveRobot();
        loadRobot();
        if (checkState()) {
            break;
        }
    }
}

void printResult() {
    cout << result << "\n";
}

void turnAround() {
    if (--loadIndex == 0) {
        loadIndex = 2 * n;
    }

    if (--unloadIndex == 0) {
        unloadIndex = 2 * n;
    }

    unloadRobot();
}

void moveRobot() {
    for (int i = 0; i < robotPositions.size(); i++) {
        int robotPosition = robotPositions[i];
        int nextPosition = robotPosition + 1;
        if (nextPosition > 2 * n) {
            nextPosition = 1;
        }

        if (!isLoaded[nextPosition] && durabilities[nextPosition] >= 1) {
            robotPositions[i] = nextPosition;
            isLoaded[robotPosition] = false;
            isLoaded[nextPosition] = true;
            durabilities[nextPosition]--;
        }
    }

    unloadRobot();
}

void loadRobot() {
    if (durabilities[loadIndex] != 0) {
        robotPositions.push_back(loadIndex);
        isLoaded[loadIndex] = true;
        durabilities[loadIndex]--;
    }
}

void unloadRobot() {
    if (isLoaded[unloadIndex]) {
        int offset = -1;
        for (int i = 0; i < robotPositions.size(); i++) {
            if (robotPositions[i] == unloadIndex) {
                offset = i;
                break;
            }
        }

        robotPositions.erase(robotPositions.begin() + offset);
        isLoaded[unloadIndex] = false;
    }
}

bool checkState() {
    int count = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (durabilities[i] == 0) {
            count++;
        }
    }

    return count >= k;
}