package programmers.programmers_150370

class Solution {
    fun solution(today: String, terms: Array<String>, privacies: Array<String>): IntArray {
        var answer = mutableListOf<Int>()

        val termDict = makeTermDict(terms)
        privacies.forEachIndexed { index, privacy ->
            if (shouldDeleted(today, privacy, termDict)) {
                answer.add(index + 1)
            }
        }

        return answer.toIntArray()
    }

    private fun makeTermDict(terms: Array<String>): Map<Char, Int> {
        return mutableMapOf<Char, Int>().apply {
            terms.forEach {
                val strings = it.split(' ')
                this[strings[0][0]] = strings[1].toInt()
            }
        }
    }

    private fun shouldDeleted(today: String, privacy: String, termDict: Map<Char, Int>): Boolean {
        val todayDays: Int
        today.split('.').run {
            todayDays = this[0].toInt() * 12 * 28 + this[1].toInt() * 28 + this[2].toInt()
        }

        val privacyDays: Int
        privacy.split(' ').run {
            val paddingMonth = termDict[this[1][0]] ?: error("문제 오류")
            this[0].split('.').run {
                privacyDays = this[0].toInt() * 12 * 28 + this[1].toInt() * 28 + this[2].toInt() + paddingMonth * 28 - 1
            }
        }

        return todayDays > privacyDays
    }
}