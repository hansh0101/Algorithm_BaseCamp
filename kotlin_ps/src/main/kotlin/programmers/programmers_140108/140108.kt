package programmers.programmers_140108

class Solution {
    fun solution(s: String): Int {
        var answer: Int = 0

        var str = s
        var index = 0
        var char = ' '
        var sameCount = 0
        var diffCount = 0

        while (str.isNotEmpty()) {
            if (index == str.length) {
                answer++
                break
            }

            if (char == ' ') {
                char = str[index++]
                sameCount++
                continue
            }

            if (char == str[index++]) {
                sameCount++
            } else {
                diffCount++
            }

            if (sameCount == diffCount) {
                answer++
                str = str.substring(index)
                index = 0
                char = ' '
                sameCount = 0
                diffCount = 0
            }
        }

        return answer
    }
}