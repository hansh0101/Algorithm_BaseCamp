package programmers_86051

class Solution {
    fun solution(numbers: IntArray): Int {
        var answer: Int = 0

        for (number in numbers) {
            answer += number
        }
        answer = 45 - answer

        return answer
    }
}