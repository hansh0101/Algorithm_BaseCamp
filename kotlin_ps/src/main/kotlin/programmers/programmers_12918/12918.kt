package programmers.programmers_12918

class Solution {
    fun solution(s: String): Boolean {
        var answer = true

        if (s.length != 4 && s.length != 6) {
            answer = false
        } else {
            for (c in s) {
                if (c.code - '0'.code < 0 || c.code - '0'.code > 9) {
                    answer = false
                    break
                }
            }
        }

        return answer
    }
}