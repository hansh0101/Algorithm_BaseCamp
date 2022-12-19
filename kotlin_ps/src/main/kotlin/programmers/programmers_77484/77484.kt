package programmers.programmers_77484

class Solution {
    fun solution(lottos: IntArray, win_nums: IntArray): IntArray {
        var answer = IntArray(2) { 0 }

        var correctCount = 0
        var zeroCount = 0
        for (lotto in lottos) {
            if (lotto == 0) {
                zeroCount++
                continue
            }
            if (win_nums.contains(lotto)) {
                correctCount++
            }
        }
        answer[0] = if (correctCount + zeroCount == 0) {
            6
        } else {
            7 - (correctCount + zeroCount)
        }
        answer[1] = if (correctCount == 0) {
            6
        } else {
            7 - correctCount
        }

        return answer
    }
}