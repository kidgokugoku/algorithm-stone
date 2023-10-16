/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode.cn/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (63.25%)
 * Likes:    1704
 * Dislikes: 0
 * Total Accepted:    472.6K
 * Total Submissions: 743.8K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k
 * 高的元素。你可以按 任意顺序 返回答案。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [1], k = 1
 * 输出: [1]
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * k 的取值范围是 [1, 数组中不相同的元素的个数]
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 *
 *
 *
 *
 * 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  class comp {
   public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
      return a.second > b.second;
    }
  };

  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (int num : nums) map[num]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    for (auto it : map) {
      pq.push(it);
      if (pq.size() > k) pq.pop();
    }
    vector<int> ans;
    while (k-- > 0) {
      ans.push_back(pq.top().first);
      pq.pop();
    }
    return ans;
  }
};
// @lc code=end
