#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int n, k;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>k;

    // queue에 1~n push
    for(int i=1;i<=n;i++) {
        q.push(i);
    }

    cout<<"<";
    // queue가 빌 때까지 반복문을 돌림
    // while(!q.empty()) 대신 while(true)로 무한루프를 돌려도 상관없음
    // while문 내부에서 queue가 비어있을 경우 탈출하는 조건문이 있기 때문 !
    while(!q.empty()) {
        for(int i=1;i<k;i++) {
            // queue의 첫 번째 ~ k-1 번째 entry를 queue 뒤에 push하고
            q.push(q.front());
            // queue의 맨 앞 entry를 pop함
            q.pop();
            // 1~k-1번째 entry는 자연스레 queue의 앞에서 뒤로 이동하게 됨
        }

        // queue의 k번째 entry를 출력
        cout<<q.front();
        // queue의 k번째 entry를 pop함
        q.pop();
        // queue의 k번째 entry는 queue에서 빠져버리게 됨

        // 바로 윗줄 q.pop() 이후 queue가 비게 된다면 '>' 를 출력하고 break를 통해 while문 탈출
        if(q.empty()) {
            cout<<">";
            break;
        }
        // q.pop() 이후에도 아직 꺼내야 할 것들이 남아있다면 ', ' 를 출력하고 while문 다시 반복
        else {
            cout << ", ";
        }
    }
    return 0;
}