package programmers.programmers_159994

class Solution {
    fun solution(cards1: Array<String>, cards2: Array<String>, goal: Array<String>): String {
        var answer: String = "Yes"

        var index1 = 0
        var index2 = 0

        goal.forEach {
            if (index1 < cards1.size) {
                if (cards1[index1] == it) {
                    index1++
                    return@forEach
                }
            }

            if (index2 < cards2.size) {
                if (cards2[index2] == it) {
                    index2++
                    return@forEach
                }
            }

            answer = "No"
        }

        return answer
    }
}