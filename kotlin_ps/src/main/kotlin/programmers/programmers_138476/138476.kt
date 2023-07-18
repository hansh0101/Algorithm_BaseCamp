package programmers.programmers_138476

class Solution {
    fun solution(k: Int, tangerine: IntArray): Int {
        var remainder = k
        var answer: Int = 0

        val map = mutableMapOf<Int, Int>()
        tangerine.forEach {
            if (map[it] == null) {
                map[it] = 1
            } else {
                map[it] = map[it]!! + 1
            }
        }

        val list = map.values.toList().sortedDescending()

        for (count in list) {
            if (remainder <= 0) {
                break
            }

            remainder -= count
            answer++
        }

        return answer
    }
}