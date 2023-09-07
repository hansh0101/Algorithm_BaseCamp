#include <iostream>
#include <vector>
#define INF 2100000000

using namespace std;

int n;
vector<int> vec;
vector<int> result;

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
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        vec.push_back(value);
    }
}

void solve() {
    int leftIndex = 0;
    int rightIndex = n - 1;
    int minValue = INF;

    while (leftIndex < rightIndex) {
        int sum = vec[leftIndex] + vec[rightIndex];
        
        if (abs(sum) < minValue) {
            minValue = abs(sum);
            result.clear();
            result.push_back(vec[leftIndex]);
            result.push_back(vec[rightIndex]);
        }

        if (sum < 0) {
            leftIndex++;
        } else if (sum > 0) {
            rightIndex--;
        } else if (sum == 0) {
            break;
        }
    }
}

void printResult() {
    cout << result[0] << " " << result[1] << "\n";
}