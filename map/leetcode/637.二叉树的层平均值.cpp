/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 *
 * https://leetcode.cn/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (69.64%)
 * Likes:    456
 * Dislikes: 0
 * Total Accepted:    156.6K
 * Total Submissions: 224K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个非空二叉树的根节点 root ,
 * 以数组的形式返回每一层节点的平均值。与实际答案相差 10^-5
 * 以内的答案可以被接受。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[3.00000,14.50000,11.00000]
 * 解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
 * 因此返回 [3, 14.5, 11] 。
 *
 *
 * 示例 2:
 *
 *
 *
 *
 * 输入：root = [3,9,20,15,7]
 * 输出：[3.00000,14.50000,11.00000]
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 *
 * 树中节点数量在 [1, 10^4] 范围内
 * -2^31 <= Node.val <= 2^31 - 1
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
  vector<double> averageOfLevels(TreeNode *root) {
    queue<TreeNode *> q;
    if (root != nullptr) q.push(root);
    vector<vector<int>> tmp;
    vector<double> ans;
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
    for (vector<int> v : tmp) {
      double t = 0;
      for (int i = 0; i < v.size(); i++) t += v[i];
      t /= v.size();
      ans.push_back(t);
    }
    return ans;
  }
};
// @lc code=end
