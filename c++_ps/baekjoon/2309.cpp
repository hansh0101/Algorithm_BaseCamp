#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 난쟁이 키 입력받음
    for(int i=0;i<9;i++) {
        int h;
        cin>>h;
        v.push_back(h);
    }

    // 출력 시 정렬된 순서로 나열해야 하기 때문에 sort
    sort(v.begin(), v.end());

    // next_permutation 활용해서 v의 가능한 모든 순서에 대해 탐색
    // 만약 0번째 entry부터 6번째 entry까지(7명)의 키의 합이 100이면 출력하고 탐색 종료
    do{
        int sum = 0;
        for(int i=0;i<7;i++) {
            sum+=v[i];
        }
        if(sum == 100) {
            for(int i=0;i<7;i++) {
                cout<<v[i]<<"\n";
            }
            break;
        }
    } while(next_permutation(v.begin(), v.end()));

    return 0;
}