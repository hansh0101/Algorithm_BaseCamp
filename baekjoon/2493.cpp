#include <iostream>
#include <stack>
using namespace std;

stack<pair<int, int>> st; // first: 탑의 높이, second: 탑의 번호(순서)
int n, h;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    // for문을 1~n까지 돌리는 이유는 첫 번째 탑의 번호가 0이 아니라 1부터 시작하기 때문 !
    for(int i=1;i<=n;i++) {
        cin>>h;

        // 접근법
        // 1-1. stack이 비었거나 stack.top().first (=높이) 가 현재 위치의 탑보다 높을 경우 stack에 현재 탑의 높이와 번호를 push함
        // 1-2-1. stack이 비었을 경우는, "나보다 높았던 탑이 없다" 라는 것과 같은 의미이므로 0을 출력
        // 1-2-2. stack.top().first (=높이) 가 현재 위치의 탑보다 높을 경우는 stack.top()이 현재 위치의 탑의 레이저를 받을 탑이므로 stack.top().second를 출력
        // 2. stack.top().first (=높이) 가 현재 위치의 탑보다 낮을 경우 stack.pop()을 실행하고, 윗줄의 조건이 될 때까지 1~2를 반복
        while(true) {
            if (st.empty()) {
                cout<<"0 ";
                st.push({h, i});
                break;
            } else {
                if (st.top().first > h) {
                    cout<<st.top().second<<" ";
                    st.push({h, i});
                    break;
                } else {
                    st.pop();
                }
            }
        }
    }
    return 0;
}