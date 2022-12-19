package programmers.programmers_132267

class Solution {
    fun solution(a: Int, b: Int, n: Int): Int {
        var answer = 0

        var current = n
        while (current >= a) {
            val exchangeUnitAmount = current / a
            current = current - exchangeUnitAmount * a + exchangeUnitAmount * b
            answer += exchangeUnitAmount * b
        }

        return answer
    }
}