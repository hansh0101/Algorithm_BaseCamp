package programmers.programmers_81301

class Solution {
    fun solution(s: String): Int {
        var answer: String = ""
        var index = 0
        val list = listOf("zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine")

        while (index < s.length) {
            if (s[index].code - '0'.code in 0..9) {
                answer += s[index]
                index++
            } else {
                list.forEachIndexed { i, str ->
                    if (s.startsWith(str, index)) {
                        answer += i.toString()
                        index += str.length
                        return@forEachIndexed
                    }
                }
            }
        }

        return answer.toInt()
    }
}