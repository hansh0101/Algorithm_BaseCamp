package programmers_12947

class Solution {
    fun solution(x: Int): Boolean {
        var answer = true

        var num = x
        var sum = 0
        while (num != 0) {
            sum += num % 10
            num /= 10
        }

        if (x % sum != 0) {
            answer = false
        }

        return answer
    }
}