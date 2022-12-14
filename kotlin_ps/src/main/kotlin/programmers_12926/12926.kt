package programmers_12926

class Solution {
    fun solution(s: String, n: Int): String {
        var answer = ""
        val max = 'z'.code - 'a'.code + 1

        for (c in s) {
            if (c.isAlphabet()) {
                val isCapital = c.code <= 'Z'.code
                var char = n + c.code
                when (isCapital) {
                    true -> {
                        if (char >= 'A'.code + max) {
                            char -= max
                        }
                    }

                    false -> {
                        if (char >= 'a'.code + max) {
                            char -= max
                        }
                    }
                }
                answer += char.toChar()
            } else {
                answer += c
            }
        }

        return answer
    }

    private fun Char.isAlphabet(): Boolean =
        (this.code >= 'a'.code && this.code <= 'z'.code) || (this.code >= 'A'.code && this.code <= 'Z'.code)
}