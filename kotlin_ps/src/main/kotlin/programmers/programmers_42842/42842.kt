package programmers.programmers_42842

import kotlin.math.sqrt

class Solution {
    private var height = 0
    private var width = 0

    fun solution(brown: Int, yellow: Int): IntArray {
        for (i in 1..getIntSqrt(yellow)) {
            if (yellow % i == 0) {
                height = i + 2
                width = yellow / i + 2

                if (brown + yellow == width * height) {
                    break
                }
            }
        }

        return intArrayOf(width, height)
    }

    private fun getIntSqrt(number: Int) : Int =
        sqrt(number.toDouble()).toInt()
}