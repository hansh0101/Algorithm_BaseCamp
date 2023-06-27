package programmers.programmers_138477

class Solution {
    fun solution(k: Int, score: IntArray): IntArray {
        var answer = IntArray(score.size)

        val list = mutableListOf<Int>()
        for (i in score.indices) {
            list.add(score[i])
            list.sortDescending()

            if (i < k - 1) {
                answer[i] = list.last()
            } else {
                answer[i] = list[k - 1]
            }
        }

        return answer
    }
}