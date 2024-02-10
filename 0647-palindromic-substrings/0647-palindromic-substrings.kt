class Solution {
    fun countSubstrings(s: String): Int {
        val n = s.length
        var count = 0
        for (i in 0 until n) {
            count += countPalindromes(s, i, i)
            count += countPalindromes(s, i, i + 1)
        }
        return count
    }

    private fun countPalindromes(s: String, left: Int, right: Int): Int {
        var count = 0
        var left = left
        var right = right
        while (left >= 0 && right < s.length && s[left] == s[right]) {
            count++
            left--
            right++
        }
        return count
    }
}
