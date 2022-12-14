package programmers_12903

class Solution {
    fun solution(s: String): String {
        return if (s.length % 2 == 1) {
            // 홀수
            s[s.length / 2].toString()
        } else {
            // 짝수
            s.substring(s.length / 2 - 1..s.length / 2)
        }
    }
}