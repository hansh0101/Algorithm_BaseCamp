#include <iostream>
#include <algorithm>
using namespace std;

// hello world
// arr[0]: h, arr[1]: e, arr[2]: l, arr[3]: o, arr[4]: w, arr[5]: r, arr[6]: d
int n;
int arr[7] = {0, 0, 0, 0, 0, 0, 0};
int add[10];
int temp[10];
int res[7];

bool check() {
    int num1 = arr[0]*10000 + arr[1]*1000 + arr[2]*110 + arr[3];
    int num2 = arr[4]*10000 + arr[3]*1000 + arr[5]*100 + arr[2]*10 + arr[6];
    if(num1 + num2 == n) {
        if(n>=100000){
            cout<<"  "<<num1<<"\n"
                <<"+ "<<num2<<"\n"
                <<"-------\n"
                <<" "<<n;
        }
        else {
            cout<<"  "<<num1<<"\n"
                <<"+ "<<num2<<"\n"
                <<"-------\n"
                <<"  "<<n;
        }
        return true;
    }
    return false;
}

void solution() {
    do {
        int cnt = 0;
        for(int i=0; i<10; i++) {
            if(temp[i] == 1) {
                res[cnt] = add[i];
                cnt++;
            }
        }

        do {
            for(int i=0; i<7; i++) {
                arr[i] = res[i];
            }
            if(arr[0] != 0 && arr[4] != 0) {
                if(check())
                    return;
            }
        } while(next_permutation(res, res+7));
    } while(next_permutation(temp, temp+10));
    cout<<"No Answer";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<10;i++) {
        add[i] = i;
    }
    for(int i=1;i<=7;i++) {
        temp[10-i] = 1;
    }
    solution();
}