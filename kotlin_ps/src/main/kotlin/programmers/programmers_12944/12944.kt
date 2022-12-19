package programmers.programmers_12944

class Solution {
    fun solution(arr: IntArray): Double {
        var answer: Double = 0.0
        for (number in arr) {
            answer += number;
        }
        answer /= arr.size
        return answer
    }
}