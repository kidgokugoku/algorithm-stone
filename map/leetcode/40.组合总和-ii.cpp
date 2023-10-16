/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode.cn/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (60.52%)
 * Likes:    1468
 * Dislikes: 0
 * Total Accepted:    469.4K
 * Total Submissions: 788K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 *
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 *
 * 注意：解集不能包含重复的组合。 
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 * 示例 2:
 *
 *
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<vector<int>> ans;
  vector<int> comb;
  int sum = 0;
  void search(vector<int>& candidates, int target, int curIndex) {
    if (sum == target) {
      ans.push_back(comb);
      return;
    }
    for (int i = curIndex;
         i < candidates.size() && sum + candidates[i] <= target; i++) {
      if (i > curIndex && candidates[i - 1] == candidates[i]) continue;
      comb.push_back(candidates[i]);
      sum += candidates[i];
      search(candidates, target, i + 1);
      sum -= candidates[i];
      comb.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    if (candidates[0] > target) return ans;
    search(candidates, target, 0);
    return ans;
  }
};
// @lc code=end
