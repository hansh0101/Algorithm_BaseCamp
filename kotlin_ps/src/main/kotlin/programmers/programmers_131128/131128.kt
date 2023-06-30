package programmers.programmers_131128

import kotlin.math.min

class Solution {
    fun solution(X: String, Y: String): String {
        var str = StringBuilder()

        val xCount = IntArray(10) { _ -> 0 }
        val yCount = IntArray(10) { _ -> 0 }

        X.forEach {
            xCount[Character.getNumericValue(it)]++
        }
        Y.forEach {
            yCount[Character.getNumericValue(it)]++
        }

        for (i in 9 downTo 0) {
            val count = min(xCount[i], yCount[i])
            repeat(count) {
                str.append(i.toString())
            }
        }

        var answer = str.toString()
        if (answer == "") {
            answer = "-1"
        }
        if (answer.startsWith('0'))  {
            answer = "0"
        }

        return answer
    }
}