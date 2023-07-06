package programmers.programmers_178871

class Solution {
    fun solution(players: Array<String>, callings: Array<String>): Array<String> {
        val rankingMap = mutableMapOf<String, Int>().apply {
            players.forEachIndexed { index, player ->
                this[player] = index
            }
        }

        callings.forEach { player ->
            val index = rankingMap[player] ?: error("error on configuring rankingMap!")

            players[index] = players[index - 1]
            rankingMap[players[index]] = rankingMap[players[index]]!! + 1
            players[index - 1] = player
            rankingMap[players[index - 1]] = rankingMap[players[index - 1]]!! - 1
        }

        return players
    }
}