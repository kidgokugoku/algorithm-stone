/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 *
 * https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (66.36%)
 * Likes:    340
 * Dislikes: 0
 * Total Accepted:    131.5K
 * Total Submissions: 198.1K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
 *
 *
 *
 * 示例1：
 *
 *
 *
 *
 * 输入: root = [1,3,2,5,3,null,9]
 * 输出: [1,3,9]
 *
 *
 * 示例2：
 *
 *
 * 输入: root = [1,2,3]
 * 输出: [1,3]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 二叉树的节点个数的范围是 [0,10^4]
 * -2^31 <= Node.val <= 2^31 - 1
 *
 *
 *
 *
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<int> largestValues(TreeNode *root) {
    queue<TreeNode *> q;
    if (root != nullptr) q.push(root);
    vector<vector<int>> tmp;
    vector<int> ans;
    while (!q.empty()) {
      int size = q.size();
      vector<int> vec;
      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        vec.push_back(node->val);
        q.pop();
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
      }
      tmp.push_back(vec);
    }
    for (int i = 0; i < tmp.size(); i++) {
      int m = INT_MIN;
      for (int j = 0; j < tmp[i].size(); j++) {
        m = max(m, tmp[i][j]);
      }
      ans.push_back(m);
    }
    return ans;
  }
};
// @lc code=end
