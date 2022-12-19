package programmers.programmers_135808

class Solution {
    fun solution(k: Int, m: Int, score: IntArray): Int {
        var answer: Int = 0
        var count = 0

        val sortedScore = score.sorted().reversed()
        while (count != (sortedScore.size / m) * m) {
            val box = sortedScore.slice(count until count + m)
            answer += m * box[m - 1]
            count += m
        }

        return answer
    }
}