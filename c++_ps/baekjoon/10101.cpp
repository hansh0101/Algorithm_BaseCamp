#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int arr[3];
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }

    // 1. 에러 검증
    if (arr[0] + arr[1] + arr[2] != 180) {
        cout << "Error\n";
        return 0;
    }

    // 2. 정삼각형
    if (arr[0] == 60 && arr[1] == 60 && arr[2] == 60) {
        cout << "Equilateral\n";
        return 0;
    }

    // 3. 이등변삼각형
    if (arr[0] == arr[1] || arr[1] == arr[2] || arr[2] == arr[1]) {
        cout << "Isosceles\n";
        return 0;
    }

    // 4. 그냥 삼각형
    cout << "Scalene\n";
    return 0;
}