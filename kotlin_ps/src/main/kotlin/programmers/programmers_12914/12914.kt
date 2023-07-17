package programmers.programmers_12914

class Solution {
    fun solution(n: Int): Long {
        val array = Array<Long>(2001) { _ -> 0}

        array[0] = 0
        array[1] = 1
        array[2] = 2
        for (i in 3..n) {
            array[i] = (array[i - 1] + array[i - 2]) % 1234567
        }

        return array[n]
    }
}