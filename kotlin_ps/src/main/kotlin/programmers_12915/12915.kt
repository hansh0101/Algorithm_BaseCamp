package programmers_12915

class Solution {
    fun solution(strings: Array<String>, n: Int): Array<String> {
        val comparator: Comparator<String> = compareBy<String> { it[n] }.thenBy { it }
        var answer = strings.sortedWith(comparator)
        return answer.toTypedArray()
    }
}