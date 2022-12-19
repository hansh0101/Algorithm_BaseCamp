package programmers.programmers_12943

class Solution {
    fun solution(num: Int): Int {
        var answer = 0

        var n: Long = num.toLong()
        var count = 0
        while (n != 1L && count < 500) {
            count++
            if (n % 2 == 0L) {
                n /= 2
            } else {
                n = n * 3 + 1
            }
        }

        if (count >= 500) {
            answer = -1
        } else {
            answer = count
        }

        return answer
    }
}