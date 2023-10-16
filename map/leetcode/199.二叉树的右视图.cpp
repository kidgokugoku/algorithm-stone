/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode.cn/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (65.69%)
 * Likes:    970
 * Dislikes: 0
 * Total Accepted:    327.7K
 * Total Submissions: 494.9K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一个二叉树的 根节点
 * root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1,3,4]
 *
 *
 * 示例 2:
 *
 *
 * 输入: [1,null,3]
 * 输出: [1,3]
 *
 *
 * 示例 3:
 *
 *
 * 输入: []
 * 输出: []
 *
 *
 *
 *
 * 提示:
 *
 *
 * 二叉树的节点个数的范围是 [0,100]
 * -100  
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
  vector<int> rightSideView(TreeNode *root) {
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
    for (vector<int> v : tmp) ans.push_back(*(v.end() - 1));
    return ans;
  }
};
// @lc code=end
