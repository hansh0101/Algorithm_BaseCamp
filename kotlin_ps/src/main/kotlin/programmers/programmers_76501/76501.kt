package programmers.programmers_76501

class Solution {
    fun solution(absolutes: IntArray, signs: BooleanArray): Int {
        var answer: Int = 0

        for (i in absolutes.indices) {
            answer += if (signs[i]) {
                absolutes[i]
            } else {
                -absolutes[i]
            }
        }

        return answer
    }
}