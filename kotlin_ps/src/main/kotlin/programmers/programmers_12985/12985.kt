package programmers.programmers_12985

class Solution {
    fun solution(n: Int, a: Int, b: Int): Int {
        var answer = 0

        var numA = a
        var numB = b

        while (numA != numB) {
            numA = getNextNumber(numA)
            numB = getNextNumber(numB)
            answer++
        }

        return answer
    }

    private fun getNextNumber(currentNumber: Int): Int =
        if (currentNumber % 2 == 0) currentNumber / 2
        else (currentNumber + 1) / 2
}