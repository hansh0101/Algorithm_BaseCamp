package programmers.programmers_136798

import kotlin.math.sqrt

class Solution {
    fun solution(number: Int, limit: Int, power: Int): Int {
        var answer: Int = 0

        getPrimeCounts(number).forEach { primeCount ->
            if (primeCount > limit) {
                answer += power
            } else {
                answer += primeCount
            }
        }

        return answer
    }

    private fun getPrimeCounts(number: Int): List<Int> {
        val primeCounts = mutableListOf<Int>()

        for (i in 1..number) {
            var primeCount = 0
            for (j in 1..sqrt(i.toDouble()).toInt()) {
                if (i % j == 0) {
                    if (i / j == j) {
                        primeCount++
                    } else {
                        primeCount += 2
                    }
                }
            }
            primeCounts.add(primeCount)
        }

        return primeCounts
    }
}