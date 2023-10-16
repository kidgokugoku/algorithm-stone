#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 *
 * https://leetcode.cn/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (51.05%)
 * Likes:    1060
 * Dislikes: 0
 * Total Accepted:    212.3K
 * Total Submissions: 413K
 * Testcase Example:  '"abab"'
 *
 * 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "abab"
 * 输出: true
 * 解释: 可由子串 "ab" 重复两次构成。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "aba"
 * 输出: false
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "abcabcabcabc"
 * 输出: true
 * 解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 *
 * 1 <= s.length <= 10^4
 * s 由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
 public:
  void getNext(int* next, string s) {
    int j = -1;
    next[0] = j;
    for (int i = 1; i < s.length(); i++) {
      while (j >= 0 && s[i] != s[j + 1]) j = next[j];
      if (s[i] == s[j + 1]) j++;
      next[i] = j;
    }
  }
  bool repeatedSubstringPattern(string s) {
    int len = s.length();
    if (len == 0) return false;
    int next[len];
    getNext(next, s);
    if (next[len - 1] != -1 && len % (len - next[len - 1] - 1) == 0)
      return true;
    return false;
  }
};
// @lc code=end
#include <bits/stdc++.h>
using namespace std;
void getNext(int* next, string s) {
  int j = -1;
  next[0] = j;
  for (int i = 1; i < s.length(); i++) {
    while (j >= 0 && s[i] != s[j + 1]) j = next[j];
    if (s[i] == s[j + 1]) j++;
    next[i] = j;
  }
}
bool repeatedSubstringPattern(string s) {
  int len = s.length();
  if (len == 0) return false;
  int next[len];
  getNext(next, s);
  for (int a : next) cout << a << endl;
  if (next[len - 1] != -1 && len % (len - next[len - 1] - 1) == 0) return true;
  return false;
}
int main() { repeatedSubstringPattern(string("abcabcabcabc")); }