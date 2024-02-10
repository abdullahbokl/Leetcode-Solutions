class Solution {
    func countSubstrings(_ s: String) -> Int {
        let n = s.count
        var count = 0
        for i in 0..<n {
            count += countPalindromes(s, i, i)
            count += countPalindromes(s, i, i + 1)
        }
        return count
    }

    private func countPalindromes(_ s: String, _ left: Int, _ right: Int) -> Int {
        var count = 0
        var left = left
        var right = right
        while left >= 0 && right < s.count && s[s.index(s.startIndex, offsetBy: left)] == s[s.index(s.startIndex, offsetBy: right)] {
            count += 1
            left -= 1
            right += 1
        }
        return count
    }
}
