package programmers_77884

import kotlin.math.*

class Solution {
    fun solution(left: Int, right: Int): Int {
        var answer: Int = 0

        for (i in left..right) {
            answer += if (sqrt(i.toDouble()) - sqrt(i.toDouble()).toInt() == 0.0) {
                -i
            } else {
                i
            }
        }

        return answer
    }
}