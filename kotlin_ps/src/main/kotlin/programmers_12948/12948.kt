package programmers_12948

class Solution {
    fun solution(phone_number: String): String {
        var answer = ""

        phone_number.forEachIndexed { index, char ->
            if (index < phone_number.length - 4) {
                answer += '*'
            } else {
                answer += char
            }
        }

        return answer
    }
}