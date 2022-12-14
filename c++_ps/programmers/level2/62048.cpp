#include <numeric>
#define ll long long

using namespace std;

long long solution(int w,int h) {
    ll answer = (ll)w * (ll)h;

    int GCD = gcd(w, h);
    answer -= (ll)w + (ll)h - (ll)GCD;

    return answer;
}

int main() {
    cout<<"ㅋㅋ";
}