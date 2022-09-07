#include <iostream>
#include <vector>
using namespace std;

int n, input;
vector<int> v[10000]; // 0-5 / 1-3 / 2-4
vector<int> vec;
int res = -1;

void calc() {
    int sum = 0;
    for(int i=0;i<vec.size();i+=2) {
        int bottom = vec[i];
        int top = vec[i+1];
        int max = 0;
        for(int j=0;j<6;j++) {
            if(v[i/2][j] == bottom || v[i/2][j] == top) continue;
            if(v[i/2][j] > max) {
                max = v[i/2][j];
            }
        }
        sum+=max;
    }
    if(sum>res) res = sum;
}

void vecpush(int fidx, int sidx) {
    if(sidx==0) vec.push_back(v[fidx][5]);
    else if(sidx==1) vec.push_back(v[fidx][3]);
    else if(sidx==2) vec.push_back(v[fidx][4]);
    else if(sidx==3) vec.push_back(v[fidx][1]);
    else if(sidx==4) vec.push_back(v[fidx][2]);
    else if(sidx==5) vec.push_back(v[fidx][0]);
}

void brute_force(int cnt) {
    if(cnt == n) {
        calc();
        return;
    }

    if(cnt == 0) {
        for(int i=0;i<6;i++) {
            vec.push_back(v[0][i]);
            vecpush(cnt, i);
            brute_force(cnt+1);
            vec.pop_back();
            vec.pop_back();
        }
    }
    else {
        int last = vec.back();
        for(int i=0;i<6;i++) {
            if(v[cnt][i] == last) {
                vec.push_back(v[cnt][i]);
                vecpush(cnt, i);
                brute_force(cnt+1);
                vec.pop_back();
                vec.pop_back();
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<6;j++) {
            cin>>input;
            v[i].push_back(input);
        }
    }

    brute_force(0);
    calc();
    cout<<res;
    return 0;
}