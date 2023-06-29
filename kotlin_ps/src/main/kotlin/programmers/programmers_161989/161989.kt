package programmers.programmers_161989

class Solution {
    fun solution(n: Int, m: Int, section: IntArray): Int {
        var answer: Int = 0

        var coloredPosition = 0

        section.forEach { currentPosition ->
            if (coloredPosition < currentPosition) {
                coloredPosition = currentPosition + m - 1
                answer++
            }
        }

        return answer
    }
}