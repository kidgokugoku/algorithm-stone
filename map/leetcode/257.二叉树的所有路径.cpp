/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode.cn/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (70.17%)
 * Likes:    1045
 * Dislikes: 0
 * Total Accepted:    344.9K
 * Total Submissions: 487.9K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给你一个二叉树的根节点 root ，按 任意顺序
 * ，返回所有从根节点到叶子节点的路径。
 *
 * 叶子节点 是指没有子节点的节点。
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3,null,5]
 * 输出：["1->2->5","1->3"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1]
 * 输出：["1"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [1, 100] 内
 * -100 <= Node.val <= 100
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
  void go(TreeNode *cur, vector<int> &path, vector<string> &ans) {
    path.push_back(cur->val);
    if (cur->left == nullptr && cur->right == nullptr) {
      string s;
      for (int i = 0; i < path.size() - 1; i++) {
        s += to_string(path[i]);
        s += "->";
      }
      s += to_string(path[path.size() - 1]);
      ans.push_back(s);
      return;
    }

    if (cur->left) {
      go(cur->left, path, ans);
      path.pop_back();
    }
    if (cur->right) {
      go(cur->right, path, ans);
      path.pop_back();
    }
    return;
  }
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<int> path;
    vector<string> ans;
    go(root, path, ans);
    return ans;
  }
};
// @lc code=end
