#include <iostream>
using namespace std;

int board[15];
int n, ans;

// num행 i열에 퀸을 뒀을 때, 가능성이 있는지(유망한지)를 판별하는 함수
bool check(int num) {
    for(int i=0; i<num; i++) {
        // 세로 || 대각선에 퀸이 있다면
        if(board[num] == board[i] || num - i == abs(board[num] - board[i])) {
            // 유망하지 않다
            return false;
        }
    }
    // 세로 || 대각선에 퀸이 없다면 유망하다
    return true;
}

void solution(int num) {
    // 퀸 n개를 뒀다면 종료
    if(num == n) {
        ans+=1;
        return;
    }

    for(int i=0; i<n; i++) {
        board[num] = i;
        // 유망성 검사
        if(check(num)) {
            // 유망하면 다음 열 진행!
            solution(num+1);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    solution(0);
    cout<<ans;
    return 0;
}