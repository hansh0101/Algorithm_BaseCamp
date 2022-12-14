#include <iostream>
#include <limits.h>
#include <cstring>
#include <vector>

using namespace std;

int t, m, n, l;
string bitSequence;
string bitSequences;
string result;
vector<string> bitmap;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        bitmap.clear();
        bitSequence = "";
        bitSequences = "";
        result = "";

        cin >> m >> n;
        for (int i = 0; i < m; i++) {
            cin >> bitSequence;
            bitmap.push_back(bitSequence);
        }

        cin >> l >> bitSequences;
        for (int i = 0; i < l; i += n) {
            string str = bitSequences.substr(i, n);
            int hammingDistance = INT_MAX;
            int position = -1;
            for (int j = 0; j < m; j++) {
                int curHammingDistance = 0;
                for (int k = 0; k < bitmap[j].length(); k++) {
                    if (str[k] != bitmap[j][k]) {
                        curHammingDistance++;
                    }
                }
                if (curHammingDistance < hammingDistance) {
                    position = j;
                    hammingDistance = curHammingDistance;
                }
            }
            result += (char) ('A' + position);
        }
        cout << result << "\n";
    }
}