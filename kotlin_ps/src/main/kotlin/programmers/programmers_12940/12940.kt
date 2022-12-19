package programmers.programmers_12940

class Solution {
    fun solution(n: Int, m: Int): IntArray {
        var answer = IntArray(2)

        answer[0] = if (n >= m) {
            getGcd(n, m)
        } else {
            getGcd(m, n)
        }
        answer[1] = (n * m) / answer[0]

        return answer
    }

    private fun getGcd(a: Int, b: Int): Int {
        return if (a % b == 0) {
            b
        } else {
            getGcd(b, a % b)
        }
    }
}