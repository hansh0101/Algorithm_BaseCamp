package programmers_82612

class Solution {
    fun solution(price: Int, money: Int, count: Int): Long {
        var answer: Long = 0L
        for (i in 1..count) {
            answer += price.toLong() * i.toLong()
        }
        answer -= money.toLong()
        if (answer < 0) {
            answer = 0
        }
        return answer
    }
}