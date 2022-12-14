#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

bool result;
bool allZero;

void dfs(string bin, int curIndex, int parIndex, bool child) {
    if (curIndex % 2 == 1) {
        return;
    }

    int leftIndex = curIndex - curIndex / 2;
    int rightIndex = curIndex + curIndex / 2;

    if (child) {
        dfs(bin, leftIndex, curIndex, (bin[leftIndex - 1] == '1'));
        dfs(bin, rightIndex, curIndex, (bin[rightIndex - 1] == '1'));
    } else {
        if (bin[leftIndex - 1] == '1' || bin[rightIndex - 1] == '1') {
            result = false;
        }
        dfs(bin, leftIndex, curIndex, false);
        dfs(bin, rightIndex, curIndex, false);
    }
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (long long number: numbers) {
        result = true;

        string bin = "";
        while (number != 0) {
            if (number % 2 == 0) bin += '0';
            else bin += '1';
            number /= 2;
        }

        int targetPow = 0;
        while (pow(2, targetPow) > bin.length() || pow(2, targetPow + 1) <= bin.length()) {
            targetPow++;
        }
        for (int i = bin.length(); i < pow(2, targetPow + 1) - 1; i++) {
            bin += '0';
        }
        reverse(bin.begin(), bin.end());

        int rootIndex = (bin.length() + 1) / 2;
        dfs(bin, rootIndex, -1, (bin[rootIndex - 1] == '1'));
        bool check = false;
        for (int i = 1; i <= bin.length(); i += 2) {
            int index = i - 1;
            if (bin[index] == '1') check = true;
        }
        if (result && check) answer.push_back(1);
        else answer.push_back(0);
    }

    return answer;
}

int main() {
    vector<long long> numbers;
    numbers.push_back(8);
    vector<int> v = solution(numbers);
    for (auto i: v) cout << i << " ";
    cout << "\n";
}