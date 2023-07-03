package programmers.programmers_155652

class Solution {
    fun solution(s: String, skip: String, index: Int): String {
        val list = makeList(skip)
        val map = makeMap(list)

        return translate(s, index, list, map)
    }

    private fun makeList(skip: String): List<Char> {
        val list = mutableListOf<Char>()
        val skipSet = skip.toCharArray().toSet()

        for (a in 'a'..'z') {
            if (!skipSet.contains(a)) {
                list.add(a)
            }
        }

        return list.toList()
    }

    private fun makeMap(list: List<Char>): Map<Char, Int> {
        val map = mutableMapOf<Char, Int>()

        for (i in list.indices) {
            map[list[i]] = i
        }

        return map
    }

    private fun translate(s: String, index: Int, list: List<Char>, map: Map<Char, Int>): String {
        var str = StringBuilder()

        for (c in s) {
            val cIndex = map[c] ?: error("문제 오류")
            str.append(list[(cIndex + index) % list.size])
        }

        return str.toString()
    }
}