package programmers_12922

class Solution {
    fun solution(n: Int): String {
        var answer = ""

        for (i in 0 until n) {
            answer += if (i % 2 == 0) {
                "수"
            } else {
                "박"
            }
        }

        return answer
    }
}