package programmers.programmers_12919

class Solution {
    fun solution(seoul: Array<String>): String {
        var answer = ""
        seoul.forEachIndexed { index, name ->
            if (name == "Kim") {
                answer = "김서방은 ${index}에 있다"
                return@forEachIndexed
            }
        }
        return answer
    }
}