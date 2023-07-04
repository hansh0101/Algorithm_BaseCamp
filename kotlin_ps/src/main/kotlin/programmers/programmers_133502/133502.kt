package programmers.programmers_133502

class Solution {
    fun solution(ingredient: IntArray): Int {
        var answer: Int = 0

        val list = mutableListOf<Int>()
        for (i in ingredient) {
            list.add(i)

            if (list.size >= 4) {
                val index = list.size - 1

                if (list[index] == 1 && list[index - 1] == 3 && list[index - 2] == 2 && list[index - 3] == 1) {
                    answer++
                    repeat(4) {
                        list.removeLast()
                    }
                }
            }
        }

        return answer
    }
}