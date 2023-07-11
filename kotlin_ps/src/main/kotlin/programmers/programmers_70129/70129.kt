package programmers.programmers_70129

class Solution {
    private var transformToBinaryCount = 0
    private var deletedZeroCount = 0

    fun solution(s: String): IntArray {
        var str: String = s
        while (str != "1") {
            str = str.removeZero().length.toBinaryString()
            transformToBinaryCount++
        }

        return intArrayOf(transformToBinaryCount, deletedZeroCount)
    }

    private fun String.removeZero(): String {
        deletedZeroCount += this.filter { it == '0' }.length
        return this.replace("0", "")
    }

    private fun Int.toBinaryString(): String {
        val stringBuilder = StringBuilder()
        var dec = this
        while (dec != 0) {
            stringBuilder.append(dec % 2)
            dec /= 2
        }
        return stringBuilder.toString().reversed()
    }
}