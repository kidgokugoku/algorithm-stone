/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode.cn/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (73.23%)
 * Likes:    1654
 * Dislikes: 0
 * Total Accepted:    330.7K
 * Total Submissions: 450.6K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s
 * 所有可能的分割方案。
 *
 * 回文串 是正着读和反着读都一样的字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a"
 * 输出：[["a"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 仅由小写英文字母组成
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<vector<string>> ans;
  int curIndex = 0;
  vector<string> comp;
  unordered_map<string, bool> map;
  bool isPalindrome(string s) {
    bool flag = true;
    if (map[s]) return map[s];
    int left = 0, right = s.size() - 1;
    while (left < right)
      if (s[left++] != s[right--]) flag = false;
    map[s] = flag;
    return flag;
  }

  void search(string s) {
    int last = comp.size() - 1;
    if (isPalindrome(comp[last])) ans.push_back(comp);
    int size = comp[last].length();
    for (int i = 1; i < size; i++) {
      string tmp = comp[last];
      string l = tmp.substr(0, i);
      if (!isPalindrome(l)) continue;
      comp.pop_back();
      comp.push_back(l);
      comp.push_back(tmp.substr(i));
      search(s);
      comp.pop_back();
      comp.pop_back();
      comp.push_back(tmp);
    }
  }

 public:
  vector<vector<string>> partition(string s) {
    comp.push_back(s);
    search(s);
    return ans;
  }
};
// @lc code=end
