class Solution {
  final _groups = <String, List<String>>{};

  List<List<String>> groupAnagrams(List<String> strs) {
    _generateAllKeys(strs);
    _fillGroups(strs);
    return _groups.values.toList();
  }

  void _generateAllKeys(List<String> strs) {
    for (final str in strs) {
      final String key = _sortString(str);
      _groups[key] = [];
    }
  }

  void _fillGroups(List<String> strs) {
    for (final str in strs) {
      final String key = _sortString(str);
      _groups[key]!.add(str);
    }
  }

  String _sortString(String str) {
    final List<String> chars = str.split('')..sort();
    return chars.join();
  }
}