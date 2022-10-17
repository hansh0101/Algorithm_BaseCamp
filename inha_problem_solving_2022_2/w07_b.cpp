#include <iostream>
#include <cstring>
using namespace std;

int T;
string str;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> str;

		int result = 0;
		for (int i = 0; i < str.length() - 1; i++) {
			int count0 = 0;
			int count1 = 0;
			for (int j = i; j < str.length(); j++) {
				if (str[j] == '0') count0++;
				else if (str[j] == '1') count1++;

				if (count0 == count1) {
					result = max(result, j - i + 1);
				}
			}
		}
		cout << result << "\n";
	}
	return 0;
}