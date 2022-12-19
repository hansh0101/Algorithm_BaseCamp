package programmers.programmers_12932

class Solution {
    fun solution(n: Long): IntArray {
        var list = mutableListOf<Int>()
        var num: Long = n
        while (num != 0L) {
            list.add((num % 10).toInt())
            num /= 10
        }

        val answer = list.toIntArray()
        return answer
    }
}