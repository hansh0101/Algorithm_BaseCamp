#include <iostream>
#include <set>

using namespace std;

set<int> s;
int n;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 1; i <= 30; i++) {
        s.insert(i);
    }
    for (int i = 0; i < 28; i++) {
        cin >> n;
        s.erase(n);
    }

    cout << *s.begin() << "\n" << *(--s.end()) << "\n";
    return 0;
}