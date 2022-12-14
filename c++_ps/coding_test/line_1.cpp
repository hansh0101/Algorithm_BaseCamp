#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(vector<vector<int>> queries) {
    int answer = 0;

    pair<int, int> arr[1001]; // first: elemCount, second: size
    memset(arr, 0, sizeof(arr));

    for (vector<int> query: queries) {
        int arrNumber = query[0];
        int elemCount = query[1];

        if (arr[arrNumber].second == 0) {
            int arrSize = 1;
            while (arrSize < elemCount) {
                arrSize *= 2;
            }
            arr[arrNumber].first = elemCount;
            arr[arrNumber].second = arrSize;
        } else {
            int originElemCount = arr[arrNumber].first;
            int originArrSize = arr[arrNumber].second;
            if (originElemCount + elemCount <= originArrSize) {
                arr[arrNumber].first = originElemCount + elemCount;
            } else {
                while (originElemCount + elemCount > originArrSize) {
                    originArrSize *= 2;
                }
                answer += originElemCount;
                arr[arrNumber].first = originElemCount + elemCount;
                arr[arrNumber].second = originArrSize;
            }
        }
    }

    return answer;
}