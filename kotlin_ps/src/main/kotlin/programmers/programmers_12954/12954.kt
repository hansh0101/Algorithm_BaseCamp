package programmers.programmers_12954

class Solution {
    fun solution(x: Int, n: Int): LongArray {
        var answer = longArrayOf()
        var list = mutableListOf<Long>()

        for (i in 1..n) {
            list.add(x.toLong() * i.toLong())
        }
        answer = list.toLongArray()

        return answer
    }
}