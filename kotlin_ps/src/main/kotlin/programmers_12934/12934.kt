package programmers_12934

import kotlin.math.*

class Solution {
    fun solution(n: Long): Long {
        var answer: Long = -1L
        var sqrt = sqrt(n.toDouble())

        if (sqrt - sqrt.toInt() == 0.0) {
            answer = (sqrt + 1).pow(2).toLong()
        }

        return answer
    }
}