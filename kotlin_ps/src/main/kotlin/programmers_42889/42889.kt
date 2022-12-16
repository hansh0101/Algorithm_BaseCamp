package programmers_42889

class Solution {
    fun solution(N: Int, stages: IntArray): IntArray {
        var answer = intArrayOf()

        val notCleared = MutableList<Int>(N) { _ -> 0 }
        val approach = MutableList<Int>(N) { _ -> 0 }
        for (i in notCleared.indices) {
            notCleared[i] = stages.count {
                it == i + 1
            }
        }
        for (i in approach.indices) {
            approach[i] = stages.count {
                it >= i + 1
            }
        }

        val failure = mutableListOf<Pair<Double, Int>>()
        for (i in notCleared.indices) {
            failure.add(Pair(notCleared[i].toDouble() / approach[i].toDouble(), i + 1))
        }
        failure.sortWith(compareBy<Pair<Double, Int>> { -it.first }.thenBy { it.second })
        answer = failure.map { it.second }.toIntArray()

        return answer
    }
}