package programmers.programmers_161990

import kotlin.math.max
import kotlin.math.min

class Solution {
    fun solution(wallpaper: Array<String>): IntArray {
        var lux = 50
        var luy = 50
        var rdx = -1
        var rdy = -1

        for (i in wallpaper.indices) {
            for (j in wallpaper[i].indices) {
                if (wallpaper[i][j] == '#') {
                    lux = min(lux, i)
                    luy = min(luy, j)
                    rdx = max(rdx, i + 1)
                    rdy = max(rdy, j + 1)
                }
            }
        }

        return intArrayOf(lux, luy, rdx, rdy)
    }
}