package programmers_64061

class Solution {
    fun solution(board: Array<IntArray>, moves: IntArray): Int {
        var answer = 0

        val topRows = IntArray(board.size)
        for (c in board.indices) {
            for (r in board.indices) {
                if (board[r][c] != 0) {
                    topRows[c] = r
                    break
                }
            }
        }

        val list = mutableListOf<Int>()
        for (move in moves) {
            val c = move - 1
            if (topRows[c] != board.size) {
                list.add(board[topRows[c]][c])
                if (list.size >= 2 && list[list.size - 1] == list[list.size - 2]) {
                    repeat(2) {
                        list.removeLast()
                        answer++
                    }
                }
                board[topRows[c]][c] = 0
                topRows[c]++
            }
        }

        return answer
    }
}