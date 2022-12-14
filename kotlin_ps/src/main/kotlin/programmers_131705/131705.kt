package programmers_131705

class Solution {
    fun solution(number: IntArray): Int {
        return makeCombination(number, mutableListOf(), 0, 0)
    }

    private fun makeCombination(number: IntArray, list: MutableList<Int>, size: Int, index: Int): Int {
        var count = 0

        if (size == 3) {
            if (list.sum() == 0) {
                count++
            }
            return count
        }
        if (index >= number.size) {
            return count
        }

        list.add(number[index])
        count += makeCombination(number, list, size + 1, index + 1)
        list.removeLast()
        count += makeCombination(number, list, size, index + 1)

        return count
    }
}