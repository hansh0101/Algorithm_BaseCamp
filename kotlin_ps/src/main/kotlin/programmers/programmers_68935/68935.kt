package programmers.programmers_68935

class Solution {
    fun solution(n: Int): Int {
        var answer: Int = 0

        var num = n
        var str = ""
        while (num != 0) {
            str += (num % 3).toString()
            num /= 3
        }
        str = str.reversed()

        var i = 1
        for (c in str) {
            answer += (c.code - '0'.code) * i
            i *= 3
        }

        return answer
    }
}