package programmers.programmers_12950

class Solution {
    fun solution(arr1: Array<IntArray>, arr2: Array<IntArray>): Array<IntArray> {
        var answer = arr1

        for (i in arr1.indices) {
            for (j in arr1[i].indices) {
                answer[i][j] += arr2[i][j]
            }
        }

        return answer
    }
}