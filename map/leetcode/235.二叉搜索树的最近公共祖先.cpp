/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 *
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (67.65%)
 * Likes:    1155
 * Dislikes: 0
 * Total Accepted:    369.6K
 * Total Submissions: 537K
 * Testcase Example:  '[6,2,8,0,4,7,9,null,null,3,5]\n2\n8'
 *
 * 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 *
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点
 * p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 *
 * 例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
 *
 *
 *
 *
 *
 * 示例 1:
 *
 * 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * 输出: 6
 * 解释: 节点 2 和节点 8 的最近公共祖先是 6。
 *
 *
 * 示例 2:
 *
 * 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * 输出: 2
 * 解释: 节点 2 和节点 4 的最近公共祖先是 2,
 * 因为根据定义最近公共祖先节点可以为节点本身。
 *
 *
 *
 * 说明:
 *
 *
 * 所有节点的值都是唯一的。
 * p、q 为不同节点且均存在于给定的二叉搜索树中。
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 public:
  void search(TreeNode* node, vector<TreeNode*>& path, vector<TreeNode*>& pathp,
              vector<TreeNode*>& pathq, TreeNode* p, TreeNode* q) {
    if (!pathp.empty() && !pathq.empty()) return;
    path.push_back(node);
    if (node == p) pathp = path;
    if (node == q) pathq = path;
    if (node->left) {
      search(node->left, path, pathp, pathq, p, q);
      path.pop_back();
    }
    if (node->right) {
      search(node->right, path, pathp, pathq, p, q);
      path.pop_back();
    }
    return;
  }
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> pathp, pathq, path;
    search(root, path, pathp, pathq, p, q);
    int minSize = pathp.size() < pathq.size() ? pathp.size() : pathq.size();
    for (int i = 0; i < minSize; i++)
      if (pathp[i] != pathq[i]) return pathq[i - 1];
    return pathp.size() < pathq.size() ? pathp[pathp.size() - 1]
                                       : pathq[pathq.size() - 1];
  }
};
// @lc code=end
