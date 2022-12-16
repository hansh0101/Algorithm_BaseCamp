package programmers_12977

import kotlin.math.*

class Solution {
    fun solution(nums: IntArray): Int {
        var answer = 0

        for (i in nums.indices) {
            for (j in i + 1 until nums.size) {
                for (k in j + 1 until nums.size) {
                    val sum = nums[i] + nums[j] + nums[k]
                    var flag = true
                    for (l in 2..(sqrt(sum.toDouble()).toInt())) {
                        if (sum % l == 0) {
                            flag = false
                            break
                        }
                    }
                    if (flag) {
                        answer++
                    }
                }
            }
        }

        return answer
    }
}