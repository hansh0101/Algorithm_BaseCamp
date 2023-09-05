#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int h, w;
int heights[500];
int result;

void getInput();
void solve();
void printResult();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    getInput();
    solve();
    printResult();

    return 0;
}

void getInput() {
    cin >> h >> w;
    for (int i = 0; i < w; i++) {
        cin >> heights[i];
    }
}

void solve() {
    int highestValue = 0;
    int index = -1;
    for (int i = 0; i < w; i++) {
        if (highestValue < heights[i]) {
            highestValue = heights[i];
            index = i;
        }
    }

    highestValue = heights[0];
    for (int i = 1; i < index; i++) {
        if (highestValue > heights[i]) {
            result += highestValue - heights[i];
        } else if (highestValue < heights[i]) {
            highestValue = heights[i];
        }
    }

    highestValue = heights[w - 1];
    for (int i = w - 2; i > index; i--) {
        if (highestValue > heights[i]) {
            result += highestValue - heights[i];
        } else if (highestValue < heights[i]) {
            highestValue = heights[i];
        }
    }
}

void printResult() {
    cout << result << "\n";
}