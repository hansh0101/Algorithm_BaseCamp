package programmers.programmers_172928

class Solution {
    fun solution(park: Array<String>, routes: Array<String>): IntArray {
        var r = 0
        var c = 0
        val mr = intArrayOf(0, 0, 1, -1)
        val mc = intArrayOf(1, -1, 0, 0)

        for (i in park.indices) {
            for (j in park[i].indices) {
                if (park[i][j] == 'S') {
                    r = i
                    c = j
                }
            }
        }

        val maxR = park.size - 1
        val maxC = park[0].length - 1

        for (route in routes) {
            val originR = r
            val originC = c

            val direction: Char
            val count: Int

            route.split(' ').run {
                direction = this[0][0]
                count = this[1].toInt()
            }

            val moveIndex = Direction.getIndex(direction)
            var stuck = false
            var isOut = false
            for (i in 0 until count) {
                r += mr[moveIndex]
                c += mc[moveIndex]

                if (r < 0 || c < 0 || r > maxR || c > maxC) {
                    isOut = true
                    break
                }

                if (park[r][c] == 'X') {
                    stuck = true
                    break
                }
            }

            if (stuck || isOut) {
                r = originR
                c = originC
            }
        }

        return intArrayOf(r, c)
    }

    enum class Direction(private val index: Int, private val char: Char) {
        EAST(0, 'E'), WEST(1, 'W'), SOUTH(2, 'S'), NORTH(3, 'N');

        companion object {
            fun getIndex(char: Char): Int = Direction.values().find { it.char == char }?.index ?: -1
        }
    }
}