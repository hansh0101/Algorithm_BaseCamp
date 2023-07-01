package programmers.programmers_160586

import kotlin.math.min

class Solution {
    fun solution(keymap: Array<String>, targets: Array<String>): IntArray {
        var answer = IntArray(targets.size)

        val array = IntArray(26) { _ -> MAX }
        keymap.forEach { str ->
            str.forEachIndexed { index, char ->
                array[char.toIndex()] = min(array[char.toIndex()], index + 1)
            }
        }

        targets.forEachIndexed { index, str ->
            var count = 0
            for (char in str) {
                when (array[char.toIndex()]) {
                    MAX -> {
                        count = -1
                        break
                    }
                    else -> {
                        count += array[char.toIndex()]
                    }
                }
            }

            answer[index] = count
        }

        return answer
    }

    private fun Char.toIndex(): Int = this.code - 'A'.code

    companion object {
        const val MAX = 100
    }
}