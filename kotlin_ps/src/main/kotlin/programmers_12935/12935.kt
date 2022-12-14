package programmers_12935

class Solution {
    fun solution(arr: IntArray): IntArray {
        var answer = intArrayOf()

        var arrList = arr.toMutableList()
        arrList.sort()
        val min = arrList[0]
        var list = mutableListOf<Int>()
        for (i in arr) {
            if (i != min) {
                list.add(i)
            }
        }

        if (list.isEmpty()) {
            list.add(-1)
        }
        answer = list.toIntArray()

        return answer
    }
}