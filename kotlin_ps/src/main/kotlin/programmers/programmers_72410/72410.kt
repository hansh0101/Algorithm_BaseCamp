package programmers.programmers_72410

class Solution {
    fun solution(new_id: String): String {
        var answer: String = new_id

        // 1. 대문자를 소문자로
        answer = answer.lowercase()

        // 2. 알파벳 소문자, 숫자, 빼기, 밑줄, 마침표 제외 모든 문자 제거
        answer = answer.filter {
            it.code in 'a'.code..'z'.code ||
                    it.code in '0'.code..'9'.code ||
                    it == '-' ||
                    it == '_' ||
                    it == '.'
        }

        // 3. 마침표 2번 이상을 마침표 1번으로
        var flag = false
        val copiedAnswer = answer
        answer = ""
        for (c in copiedAnswer) {
            if (flag) {
                if (c != '.') {
                    answer += c
                    flag = false
                }
            } else {
                if (c == '.') {
                    flag = true
                }
                answer += c
            }
        }

        // 4. 처음이나 끝이 마침표면 제거
        if (answer.isNotEmpty() && answer.first() == '.') {
            answer = answer.drop(1)
        }
        if (answer.isNotEmpty() && answer.last() == '.') {
            answer = answer.dropLast(1)
        }

        // 5. 빈 문자열이라면 a 대입
        if (answer.isEmpty()) {
            answer = "a"
        }

        // 6. 길이 15 제한
        if (answer.length > 15) {
            answer = answer.slice(0 until 15)
        }
        if (answer.isNotEmpty() && answer.last() == '.') {
            answer = answer.dropLast(1)
        }

        // 7. 길이가 2 이하면 길이가 3 될 때까지 마지막 문자 반복해 추가
        while (answer.length <= 2) {
            answer += answer.last()
        }

        return answer
    }
}