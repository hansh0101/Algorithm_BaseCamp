#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

// front와 back에서 삽입, 삭제를 하기 위해 deque 사용함
deque<int> dq;
// 입력받은 수열을 담아뒀다가 그 수열을 역순으로 바꿔주기 위해 vector 사용함
vector<int> v;
int n, x;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    // 수열을 vector에 push_back
    for(int i=0; i < n; i++) {
        cin>>x;
        v.push_back(x);
    }

    // vector를 역순으로 정렬함
    reverse(v.begin(), v.end());
    // 정렬하는 이유:
    // 입력받은 순서의 역순으로 확인할 경우 되감기하여 원래 순서를 더 쉽게 추론할 수 있음
    // ex) 2 3 3 2 1 -> 1 2 3 3 2 로 할 경우
    // 1: 손에 있는 카드 중 맨 위의 것(맨 앞의 것) 을 뽑은 경우 -> push_front()
    // 2: 손에 있는 카드 중 위에서 2번째 것(앞에서 2번째 것) 을 뽑은 경우
    // -> 맨 앞의 것을 잠깐 빼놨다가, push_front() 로 현재 번호 카드를 넣고,
    // -> 잠깐 빼둔 카드를 다시 push_front()
    // 3: 손에 있는 카드 중 맨 밑의 것(맨 뒤의 것) 을 뽑은 경우 -> push_back()
    // 역순으로 하지 않을 경우, 삽입이 deque의 앞뒤에서 일어나는 것이 아닌 중간에 insert해야 하는 경우가 생기는데
    // 이 때 시간초과가 발생할 수 있음 !!!

    for (int i = 0; i < n; i++) {
        // 1: 손에 있는 카드 중 맨 위의 것을 뽑은 경우
        if (v[i] == 1) {
            // i+1번 카드를 deque의 맨 앞에 push함
            dq.push_front(i + 1);
        }
        // 2: 손에 있는 카드 중 위에서 2번째 것을 뽑은 경우
        else if (v[i] == 2) {
            // 맨 앞에 있는 카드를 temp에 잠시 담아뒀다가,
            int temp = dq.front();
            // 맨 앞에 있는 카드를 pop하고,
            dq.pop_front();
            // i+1번 카드를 맨 앞에 push하고,
            dq.push_front(i + 1);
            // 잠깐 빼둔 temp번 카드를 맨 앞에 push하면
            dq.push_front(temp);
            // 앞에서 2번째를 뽑은 카드를 복구하는 것과 똑같음 !
        }
        // 3: 손에 있는 카드 중에서 맨 밑의 것을 뽑은 경우
        else if (v[i] == 3) {
            // i+1번 카드를 맨 뒤에 push함
            dq.push_back(i+1);
        }
    }

    // deque 출력
    for(int i=0;i<n;i++) {
        cout<<dq[i]<<" ";
    }

    return 0;
}