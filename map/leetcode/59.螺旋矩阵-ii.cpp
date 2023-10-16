/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode.cn/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (75.66%)
 * Likes:    1176
 * Dislikes: 0
 * Total Accepted:    356.2K
 * Total Submissions: 494.8K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1
 * 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 1, left = 0, right = n - 1, top = 1, bottom = n - 1, dir = 0,
             x = 0, y = 0;
         i <= n * n; i++) {
      ans[y][x] = i;
      switch (dir) {
        case 0:
          if (++x == right) {
            dir = 1;
            right--;
          }

          break;
        case 1:
          if (++y == bottom) {
            dir = 2;
            bottom--;
          }
          break;
        case 2:
          if (--x == left) {
            dir = 3;
            left++;
          }
          break;
        case 3:
          if (--y == top) {
            dir = 0;
            top++;
          }
          break;
        default:
          break;
      }
    }
    return ans;
  }
};
// @lc code=end
