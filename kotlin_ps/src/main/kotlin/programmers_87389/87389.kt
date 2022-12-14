package programmers_87389

class Solution {
    fun solution(n: Int): Int {
        var answer: Int = 0

        for (i in 1 until n) {
            if (n % i == 1) {
                answer = i
                break
            }
        }

        return answer
    }
}