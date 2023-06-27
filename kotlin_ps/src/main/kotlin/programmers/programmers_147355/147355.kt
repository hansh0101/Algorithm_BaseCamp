package programmers.programmers_147355

class Solution {
    fun solution(t: String, p: String): Int {
        var answer: Int = 0

        val pLong = p.toLong()
        for (i in 0..t.length - p.length) {
            val subLong = t.substring(i, i + p.length).toLong()

            if (subLong <= pLong) {
                answer++
            }
        }

        return answer
    }
}