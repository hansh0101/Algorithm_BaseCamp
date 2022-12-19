package programmers.programmers_142086

class Solution {
    fun solution(s: String): IntArray {
        var answer = IntArray(s.length)

        val dict = mutableMapOf<Char, Int>()
        s.forEachIndexed { index, c ->
            if (dict.containsKey(c)) {
                answer[index] = index - dict.getValue(c)
                dict[c] = index
                return@forEachIndexed
            }

            answer[index] = -1
            dict[c] = index
        }

        return answer
    }
}