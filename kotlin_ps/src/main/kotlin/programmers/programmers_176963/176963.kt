package programmers.programmers_176963

class Solution {
    fun solution(name: Array<String>, yearning: IntArray, photo: Array<Array<String>>): IntArray {
        var answer = IntArray(photo.size)

        val dict = mutableMapOf<String, Int>()
        for (i in name.indices) {
            dict[name[i]] = yearning[i]
        }

        photo.forEachIndexed { index, names ->
            var sum = 0
            names.forEach {
                sum += dict[it] ?: 0
            }
            answer[index] = sum
        }

        return answer
    }
}