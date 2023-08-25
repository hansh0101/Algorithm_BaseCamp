#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Title {
    int value;
    string title;

    Title(int value, string title) {
        this->value = value;
        this->title = title;
    }
};

int n, m;
string title;
int value;
vector<Title> vec;

string findTitle(int value) {
    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (vec[mid].value >= value) {
            right = mid - 1;
        } else if (vec[mid].value < value) {
            left = mid + 1;
        }
    }

    if (vec[mid].value < value) {
        return vec[mid + 1].title;
    }
    return vec[mid].title;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> title >> value;
        vec.push_back(Title(value, title));
    }
    for (int i = 0; i < m; i++) {
        cin >> value;
        cout << findTitle(value) << "\n";
    }

    return 0;
}