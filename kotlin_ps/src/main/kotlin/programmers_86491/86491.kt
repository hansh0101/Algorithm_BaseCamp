package programmers_86491

class Solution {
    fun solution(sizes: Array<IntArray>): Int {
        var maxMax = 0
        var maxMin = 0

        for (intArray in sizes) {
            if (intArray[0] < intArray[1]) {
                intArray[0] = intArray[1].also { intArray[1] = intArray[0] }
            }
            if (intArray[0] > maxMax) {
                maxMax = intArray[0]
            }
            if (intArray[1] > maxMin) {
                maxMin = intArray[1]
            }
        }
        return maxMax * maxMin
    }
}