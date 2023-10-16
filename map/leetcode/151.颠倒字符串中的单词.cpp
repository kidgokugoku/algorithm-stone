#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 颠倒字符串中的单词
 *
 * https://leetcode.cn/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (50.78%)
 * Likes:    1039
 * Dislikes: 0
 * Total Accepted:    456.6K
 * Total Submissions: 863.7K
 * Testcase Example:  '"the sky is blue"'
 *
 * 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
 *
 * 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词
 * 分隔开。
 *
 * 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
 *
 * 注意：输入字符串
 * s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "the sky is blue"
 * 输出："blue is sky the"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "  hello world  "
 * 输出："world hello"
 * 解释：反转后的字符串中不能存在前导空格和尾随空格。
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "a good   example"
 * 输出："example good a"
 * 解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 包含英文大小写字母、数字和空格 ' '
 * s 中 至少存在一个 单词
 *
 *
 *
 *
 *
 *
 *
 * 进阶：如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 O(1)
 * 额外空间复杂度的 原地 解法。
 *
 */

// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    int slow = 0, fast = 0;
    while (fast < s.length()) {
      while (fast < s.length() && s[fast] == ' ') fast++;
      while (fast < s.length() && s[fast] != ' ') swap(s[slow++], s[fast++]);
      slow++;
      fast++;
    }
    s.resize(slow - 1);
    if (s[s.length() - 1] == ' ') slow--;
    s.resize(slow - 1);
    for (int i = 0, j = s.length() - 1; i < j;) swap(s[i++], s[j--]);
    for (int i = 0, j = 0; i < s.length();) {
      while (s[++j] != ' ' && j < s.length())
        ;
      int k = j - 1;
      while (i < k) swap(s[i++], s[k--]);
      i = j + 1;
    }
    return s;
  }
};
// @lc code=end
#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s) {
  int slow = 0, fast = 0;
  while (fast < s.length()) {
    while (fast < s.length() && s[fast] == ' ') fast++;
    while (fast < s.length() && s[fast] != ' ') swap(s[slow++], s[fast++]);
    slow++;
    fast++;
  }
  cout << s << endl;
  s.resize(slow - 1);
  cout << s << endl;
  if (s[s.length() - 1] == ' ') slow--;
  s.resize(slow - 1);
  cout << s << endl;
  for (int i = 0, j = s.length() - 1; i < j;) swap(s[i++], s[j--]);
  cout << s << endl;
  for (int i = 0, j = 0; i < s.length();) {
    while (s[++j] != ' ' && j < s.length())
      ;
    int k = j - 1;
    while (i < k) swap(s[i++], s[k--]);
    i = j + 1;
  }
  return s;
}
int main() {
  cout << reverseWords(string("  hello world  ")) << endl;
  cout << reverseWords(string("a good   example"));
}