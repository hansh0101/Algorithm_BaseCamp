package programmers.programmers_42862

class Solution {
    fun solution(n: Int, lost: IntArray, reserve: IntArray): Int {
        val counts = MutableList<Int>(n + 2) { 1 }
        for (num in lost) {
            counts[num]--
        }
        for (num in reserve) {
            counts[num]++
        }
        for (i in 1..n) {
            if (counts[i] == 0) {
                if (counts[i - 1] == 2) {
                    counts[i] = 1
                    counts[i - 1] = 1
                    continue
                }
                if (counts[i + 1] == 2) {
                    counts[i] = 1
                    counts[i + 1] = 1
                    continue
                }
            }
        }

        return counts.slice(1..n)
            .count { it != 0 }
    }
}