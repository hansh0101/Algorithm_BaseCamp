package programmers.programmers_68644

class Solution {
    fun solution(numbers: IntArray): IntArray {
        val set = mutableSetOf<Int>()
        for (i in numbers.indices) {
            for (j in i + 1 until numbers.size) {
                set.add(numbers[i] + numbers[j])
            }
        }
        return set.sorted().toIntArray()
    }
}