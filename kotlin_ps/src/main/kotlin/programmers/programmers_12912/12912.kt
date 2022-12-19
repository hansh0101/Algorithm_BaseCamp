package programmers.programmers_12912

class Solution {
    fun solution(a: Int, b: Int): Long {
        var answer: Long = 0

        if (a <= b) {
            for (i in a..b) {
                answer += i.toLong()
            }
        } else {
            for (i in b..a) {
                answer += i.toLong()
            }
        }

        return answer
    }
}