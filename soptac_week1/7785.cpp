#include <iostream>
#include <set>
using namespace std;

// 이름을 역순으로 정렬해야 하므로 greater<string> 사용함
// set은 삽입 순서에 관계없이 default로 내림차순으로 정렬함(abc ... z 순)
// set에 회사에 있는 사람의 이름을 넣음
set<string, greater<string>> s;
int n;
string name, log;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>name>>log;

        // name이라는 사람이 출근한 경우
        if(log == "enter") {
            // set에 name을 insert함
            s.insert(name);
            // Q. 만약 set에 name이라는 사람이 이미 있으면 어떻게 하나 ?
            // A. 상관없음. 왜냐하면 set은 key의 중복을 허용하지 않기 때문에 알아서 중복 insert를 처리해줌
        }
            // name이라는 사람이 퇴근한 경우
        else if(log == "leave") {
            // set에서 name을 erase함
            s.erase(name);
            // Q. 만약 set에 name이라는 사람이 없으면 어떻게 하나 ?
            // A. 상관없음. 왜냐면 set의 erase(key) 는 해당 key를 가진 원소가 삭제된 횟수를 return 하기 때문에
            // 만약 없는 name에 대해서 삭제할 경우 실제로는 아무것도 삭제되지 않고 0을 return하게 됨
        }
    }

    // set은 인덱스로 접근할 수 없기 때문에 auto를 사용하여 set에 들어있는 entry에 접근함
    for(auto i: s) {
        cout<<i<<"\n";
    }

    return 0;
}