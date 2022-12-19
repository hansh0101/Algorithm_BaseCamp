package programmers.programmers_42748

class Solution {
    fun solution(array: IntArray, commands: Array<IntArray>): IntArray {
        var answer = IntArray(commands.size)

        repeat(commands.size) { index ->
            val list = array.slice(commands[index][0] - 1 until commands[index][1]).sorted()
            answer[index] = list[commands[index][2] - 1]
        }

        return answer
    }
}