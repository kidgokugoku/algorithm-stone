#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 *
 * https://leetcode.cn/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (71.67%)
 * Likes:    351
 * Dislikes: 0
 * Total Accepted:    89.4K
 * Total Submissions: 127K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * 给你一个字符串数组 words ，请你找出所有在 words
 * 的每个字符串中都出现的共用字符（ 包括重复字符），并以数组形式返回。你可以按
 * 任意顺序 返回答案。
 *
 *
 * 示例 1：
 *
 *
 * 输入：words = ["bella","label","roller"]
 * 输出：["e","l","l"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：words = ["cool","lock","cook"]
 * 输出：["c","o"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 100
 * words[i] 由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    int a[26] = {}, b[26] = {};
    string s = words[0];
    for (int i = 0; i < s.length(); i++) a[s[i] - 'a']++;
    for (int j = 1; j < words.size(); j++) {
      memset(b, 0, 26 * sizeof(int));
      string ss = words[j];
      for (int i = 0; i < ss.length(); i++) b[ss[i] - 'a']++;
      for (int i = 0; i < 26; i++) a[i] = a[i] < b[i] ? a[i] : b[i];
    }
    vector<string> ans;
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < a[i]; j++) ans.push_back(string(1, char(i + 'a')));

    return ans;
  }
};
// @lc code=end
