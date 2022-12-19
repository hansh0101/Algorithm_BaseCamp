package programmers.programmers_12910

class Solution {
    fun solution(arr: IntArray, divisor: Int): IntArray {
        var answer = intArrayOf()

        var list = mutableListOf<Int>()
        for (number in arr) {
            if (number % divisor == 0) {
                list.add(number)
            }
        }

        if (list.isEmpty()) {
            list.add(-1)
        }
        list.sort()
        answer = list.toIntArray()

        return answer
    }
}