#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int l, c;
char arr[15];

void bt(string password, int ja, int mo, int curPos) {
    // 만든 문자열의 길이가 l이라면
    if(password.length() == l) {
        // 조건에 만족할 경우에는 암호로 사용할 수 있음
        // 조건에 만족하지 않는 경우로는 패스워드로 사용할 수 없음
        // 조건에 만족하지 않는다면, 아래 for문을 실행할 필요가 없기 때문에
        // 조건을 만족하든 만족하지 않든 더이상 가능성을 탐색해보지 않음 !!!!
        if(ja >= 2 && mo >= 1) {
            cout << password << "\n";
        }
        return;
    }

    // 현재 position 이전의 arr[i]는 이미 테스트해본 놈임
    // 따라서, curPos부터 arr[i]를 테스트해봐야 함
    for(int i = curPos; i<c; i++) {
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
            // 모음이라면 mo+1을 해줌으로써 모음의 개수를 계속 저장하고
            bt(password+arr[i], ja, mo+1, i+1);
        }
        else {
            // 자음이라면 ja+1을 해줌으로써 자음의 개수를 계속 저장
            bt(password+arr[i], ja+1, mo, i+1);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // l: 암호 자릿수
    // c: 알파벳 갯
    cin>>l>>c;
    for(int i=0; i<c; i++) {
        cin>>arr[i];
    }

    // 사전식으로 가능성 있는 암호를 출력해야하므로, 애초에 arr를 사전식으로 정렬해두면
    // 반복문에서 arr를 앞부터 순차적으로 탐색하기 때문에 결과는 당연히 사전식으로 정렬될 것 !!
    sort(arr, arr+c);

    // backtracking 함수 돌
    bt("", 0, 0, 0);

    return 0;
}