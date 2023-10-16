/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 *
 * https://leetcode.cn/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (57.04%)
 * Likes:    1326
 * Dislikes: 0
 * Total Accepted:    370.5K
 * Total Submissions: 633K
 * Testcase Example:  '"25525511135"'
 *
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导
 * 0），整数之间用 '.' 分隔。
 *
 *
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是
 * "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
 *
 *
 * 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP
 * 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s
 * 中的任何数字。你可以按 任何 顺序返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "25525511135"
 * 输出：["255.255.11.135","255.255.111.35"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "0000"
 * 输出：["0.0.0.0"]
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "101023"
 * 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 20
 * s 仅由数字组成
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<string> ans;
  vector<string> tmp;
  void search(string s) {
    // for (int i = 0; i < tmp.size(); i++) cout << tmp[i] << endl;
    // cout << endl;
    if (tmp.size() == 4 && stoi(tmp[3]) <= 255) {
      ans.push_back(tmp[0] + '.' + tmp[1] + '.' + tmp[2] + '.' + tmp[3]);
      return;
    }
    for (int i = 1; i <= 3; i++) {
      string temp = tmp[tmp.size() - 1];
      string l = temp.substr(0, i), r = temp.substr(i);
      if (!r.size() || l.size() > 1 && l[0] == '0') return;
      if (tmp.size() == 3 && r.length() > 1 && r[0] == '0') continue;
      if (temp.length() > (4 - tmp.size() + 1) * 3) return;
      if (stoi(l) > 255) continue;
      tmp.pop_back();
      tmp.push_back(l);
      tmp.push_back(r);
      search(s);
      tmp.pop_back();
      tmp.pop_back();
      tmp.push_back(temp);
    }
  }

 public:
  vector<string> restoreIpAddresses(string s) {
    if (s.size() < 4) return ans;
    tmp.push_back(s);
    search(s);
    return ans;
  }
};
// @lc code=end
int main() {
  Solution so;
  so.restoreIpAddresses("101023");
}