package programmers.programmers_67256

import kotlin.math.*

class Solution {
    fun solution(numbers: IntArray, hand: String): String {
        var answer = ""

        var leftHandPosition = Pair(3, 0)
        var rightHandPosition = Pair(3, 2)

        for (number in numbers) {
            val numberPosition = Position.positionOf(number)

            if (numberPosition.second == 0) {
                answer += "L"
                leftHandPosition = numberPosition
            } else if (numberPosition.second == 2) {
                answer += "R"
                rightHandPosition = numberPosition
            } else {
                val leftDistance = getDistance(numberPosition, leftHandPosition)
                val rightDistance = getDistance(numberPosition, rightHandPosition)

                if (leftDistance < rightDistance) {
                    answer += "L"
                    leftHandPosition = numberPosition
                } else if (leftDistance > rightDistance) {
                    answer += "R"
                    rightHandPosition = numberPosition
                } else if (leftDistance == rightDistance) {
                    if (hand == "left") {
                        answer += "L"
                        leftHandPosition = numberPosition
                    } else if (hand == "right") {
                        answer += "R"
                        rightHandPosition = numberPosition
                    }
                }
            }
        }

        return answer
    }

    private fun getDistance(from: Pair<Int, Int>, to: Pair<Int, Int>): Int =
        max(from.first, to.first) - min(from.first, to.first) +
                max(from.second, to.second) - min(from.second, to.second)

    enum class Position(val number: Int, val position: Pair<Int, Int>) {
        ONE(1, Pair(0, 0)),
        TWO(2, Pair(0, 1)),
        THREE(3, Pair(0, 2)),
        FOUR(4, Pair(1, 0)),
        FIVE(5, Pair(1, 1)),
        SIX(6, Pair(1, 2)),
        SEVEN(7, Pair(2, 0)),
        EIGHT(8, Pair(2, 1)),
        NINE(9, Pair(2, 2)),
        ZERO(0, Pair(3, 1));

        companion object {
            fun positionOf(number: Int): Pair<Int, Int> {
                return values().find { it.number == number }!!.position
            }
        }
    }
}