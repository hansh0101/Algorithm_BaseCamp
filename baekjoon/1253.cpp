#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, num;
vector<int> vec;
set<int> goodNumber[2000];
set<int> goodNumbers;
int result;

void solution(int index) {
    int left = 0, right = N - 1;
    while (left < right) {
        int sum = vec[left] + vec[right];
        if (sum == vec[index]) {
            if (left != index && right != index) {
                result++;
                break;
            } else if (left == index) {
                left++;
            } else if (right == index) {
                right--;
            }
        } else if (sum < vec[index]) {
            left++;
        } else if (sum > vec[index]) {
            right--;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());

    for (int i = 0; i < N; i++) {
        solution(i);
    }

    cout << result << "\n";
    return 0;
}