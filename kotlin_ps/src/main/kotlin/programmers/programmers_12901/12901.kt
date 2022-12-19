package programmers.programmers_12901

class Solution {
    fun solution(a: Int, b: Int): String {
        val days = listOf<Int>(31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)
        val answers = listOf<String>("FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU")
        val sum = days.slice(0 until a - 1).sum() + b - 1
        return answers[sum % 7]
    }
}