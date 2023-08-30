#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[1500][1500];
int rowIndices[1500];
int result;

struct NumberInfo {
    int value;
    int columnIndex;

    NumberInfo(int value, int columnIndex) {
        this->value = value;
        this->columnIndex = columnIndex;
    }
};

bool compare(NumberInfo ni1, NumberInfo ni2) {
    return ni1.value > ni2.value;
}

int getMaxValue() {
    vector<NumberInfo> vec;

    for (int j = 0; j < n; j++) {
        int index = rowIndices[j];
        
        vec.push_back(NumberInfo(arr[index][j], j));
    }

    sort(vec.begin(), vec.end(), compare);

    NumberInfo greatestNumberInfo = vec[0];
    rowIndices[greatestNumberInfo.columnIndex]--;
    return greatestNumberInfo.value;
}

void getInput() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
}

void solve() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        rowIndices[i] = n - 1;
    }

    int lastMaxValue = 1e9 + 1;
    for (int i = 0; i < n; i++) {
        lastMaxValue = getMaxValue();
    }

    result = lastMaxValue;
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

    return 0;
}