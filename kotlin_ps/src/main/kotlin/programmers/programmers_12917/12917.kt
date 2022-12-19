package programmers.programmers_12917

class Solution {
    fun solution(s: String): String {
        var answer = ""

        var list = mutableListOf<Char>()
        for (c in s) {
            list.add(c)
        }
        list.sort()
        list.reverse()
        for (c in list) {
            answer += c
        }

        return answer
    }
}