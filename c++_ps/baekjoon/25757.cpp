#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int n;
char game;
set<string> players;
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> game;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        players.insert(name);
    }

    if (game == 'Y') {
        result = players.size() / 1;
    } else if (game == 'F') {
        result = players.size() / 2;
    } else if (game == 'O') {
        result = players.size() / 3;
    }

    cout << result << "\n";
    return 0;
}