#include <string>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    map<string, int> map1, map2, minMap, maxMap;
    int size1 = 0;
    int size2 = 0;

    // map에 담기
    for (int i = 0; i < str1.length() - 1; i++) {
        char a = str1[i];
        char b = str1[i + 1];

        if (!(a >= 'a' && a <= 'z') && !(a >= 'A' && a <= 'Z')) continue;
        if (!(b >= 'a' && b <= 'z') && !(b >= 'A' && b <= 'Z')) continue;

        if (a >= 'A' && a <= 'Z') {
            a = a - 'A' + 'a';
        }
        if (b >= 'A' && b <= 'Z') {
            b = b - 'A' + 'a';
        }

        string s;
        s += a;
        s += b;

        map1[s]++;
        size1++;
    }
    for (int i = 0; i < str2.length() - 1; i++) {
        char a = str2[i];
        char b = str2[i + 1];

        if (!(a >= 'a' && a <= 'z') && !(a >= 'A' && a <= 'Z')) continue;
        if (!(b >= 'a' && b <= 'z') && !(b >= 'A' && b <= 'Z')) continue;

        if (a >= 'A' && a <= 'Z') {
            a = a - 'A' + 'a';
        }
        if (b >= 'A' && b <= 'Z') {
            b = b - 'A' + 'a';
        }

        string s;
        s += a;
        s += b;

        map2[s]++;
        size2++;
    }

    if (map1.empty() && map2.empty()) {
        return 1 * 65536;
    }

    // 교집합 size 구하기
    int minSize = 0;
    for (auto s1: map1) {
        // 존재한다면
        if (map2.find(s1.first) != map2.end()) {
            minSize += min(s1.second, map2.find(s1.first)->second);
        }
    }

    int maxSize = size1 + size2 - minSize;

    double value = ((double) minSize / (double) maxSize) * 65536;
    answer = (int) value;

    return answer;
}