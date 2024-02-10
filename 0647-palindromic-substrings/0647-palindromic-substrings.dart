class Solution {
  int countSubstrings(String s) {
    final int n = s.length;
    int count = 0;
    for (int i = 0; i < n; i++) {
      count += _countPalindromes(s, i, i);
      count += _countPalindromes(s, i, i + 1);
    }
    return count;
  }

  int _countPalindromes(String s, int left, int right) {
    int count = 0;
    while (_isValid(left, right, s)) {
      left--;
      right++;
      count++;
    }
    return count;
  }

  bool _isValid(int left, int right, String s) =>
      left >= 0 && right < s.length && s[left] == s[right];
}
