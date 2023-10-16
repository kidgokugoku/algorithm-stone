/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode.cn/problems/combinations/description/
 *
 * algorithms
 * Medium (77.20%)
 * Likes:    1512
 * Dislikes: 0
 * Total Accepted:    605.5K
 * Total Submissions: 785.6K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 *
 * 你可以按 任何顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 4, k = 2
 * 输出：
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 * 示例 2：
 *
 *
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<vector<int>> ans;
  vector<int> path;
  void search(int n, int k, int startIndex) {
    if (path.size() == k) {
      ans.push_back(path);
      return;
    }
    for (int i = startIndex; i <= n; i++) {
      if (path.size() + (n - i + 1) < k) break;
      path.push_back(i);
      search(n, k, i + 1);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> combine(int n, int k) {
    search(n, k, 1);
    return ans;
  }
};
// @lc code=end
