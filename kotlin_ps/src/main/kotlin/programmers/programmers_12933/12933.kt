package programmers.programmers_12933

class Solution {
    fun solution(n: Long): Long {
        var answer: Long = 0
        var num = n
        var list = mutableListOf<Long>()

        while (num != 0L) {
            list.add(num % 10)
            num /= 10
        }

        list.sort()
        var i = 1
        for (number in list) {
            answer += number * i
            i *= 10
        }

        return answer
    }
}