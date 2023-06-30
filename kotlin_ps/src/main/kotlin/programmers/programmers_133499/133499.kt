package programmers.programmers_133499

class Solution {
    fun solution(babbling: Array<String>): Int {
        var answer: Int = 0

        val words = arrayOf("aya", "ye", "woo", "ma")
        babbling.forEach {
            var originWord = it
            var flag = true
            var lastWord = ""

            while (flag) {
                if (originWord.isEmpty()) {
                    break
                }

                var contains = false
                for (word in words) {
                    if (originWord.startsWith(word) && lastWord != word) {
                        contains = true
                        lastWord = word
                        originWord = originWord.substring(word.length)
                        break
                    }
                }

                if (!contains) {
                    flag = false
                }
            }

            if (flag) {
                answer++
            }
        }

        return answer
    }
}