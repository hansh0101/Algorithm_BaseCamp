package programmers.programmers_42840

class Solution {
    fun solution(answers: IntArray): IntArray {
        var answer = mutableListOf<Int>()

        val people = listOf<List<Int>>(
            listOf(1, 2, 3, 4, 5),
            listOf(2, 1, 2, 3, 2, 4, 2, 5),
            listOf(3, 3, 1, 1, 2, 2, 4, 4, 5, 5)
        )
        val indices = mutableListOf<Int>(0, 0, 0)
        val scores = mutableListOf<Int>(0, 0, 0)

        for (answer in answers) {
            indices.forEachIndexed { index, i ->
                if (i == people[index].size) {
                    indices[index] = 0
                }

                if (answer == people[index][indices[index]]) {
                    scores[index]++
                }
                indices[index]++
            }
        }

        scores.forEachIndexed { index, i ->
            if (i == scores.maxOrNull()) {
                answer.add(index + 1)
            }
        }

        return answer.sorted().toIntArray()
    }
}