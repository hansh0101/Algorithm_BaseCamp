package programmers_12930

class Solution {
    fun solution(s: String): String {
        var answer = ""
        var index = 0
        val offset = 'a'.code - 'A'.code

        for (c in s) {
            if (c == ' ') {
                index = 0
                answer += c
                continue
            }
            answer += if (index % 2 == 0) {
                if (c.code >= 'a'.code) {
                    (c.code - offset).toChar()
                } else {
                    c
                }
            } else {
                if (c.code >= 'a'.code) {
                    c
                } else {
                    (c.code + offset).toChar()
                }
            }
            index++
        }

        return answer
    }
}