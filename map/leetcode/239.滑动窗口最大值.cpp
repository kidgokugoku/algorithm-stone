/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode.cn/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (50.01%)
 * Likes:    2551
 * Dislikes: 0
 * Total Accepted:    498.3K
 * Total Submissions: 1M
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组
 * nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的
 * k 个数字。滑动窗口每次只向右移动一位。
 *
 * 返回 滑动窗口中的最大值 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1], k = 1
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 private:
  class myQ {
   public:
    deque<int> q;
    void pop(int val) {
      if (!q.empty() && q.front() == val) q.pop_front();
    }
    void push(int val) {
      while (!q.empty() && q.back() < val) q.pop_back();
      q.push_back(val);
    }
    int front() { return q.front(); }
  };

 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    myQ q;
    vector<int> ans;
    for (int i = 0; i < k; i++) {
      q.push(nums[i]);
    }
    ans.push_back(q.front());
    for (int i = k; i < nums.size(); i++) {
      q.pop(nums[i - k]);
      q.push(nums[i]);
      ans.push_back(q.front());
    }
    return ans;
  }
};
// @lc code=end
#include <bits/stdc++.h>
using namespace std;
class myQ {
 public:
  deque<int> q;
  void pop(int val) {
    cout << "popping" << val << endl;
    if (!q.empty() && q.front() == val) q.pop_front();
  }
  void push(int val) {
    cout << "pushing" << val << endl;
    cout << q.front() << endl;
    while (!q.empty() && q.back() < val) q.pop_back();
    cout << q.front() << endl;
    q.push_back(val);
  }
  int front() { return q.front(); }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  myQ q;
  vector<int> ans;
  for (int i = 0; i < k; i++) {
    q.push(nums[i]);
  }
  ans.push_back(q.front());
  for (int i = k; i < nums.size(); i++) {
    q.pop(nums[i - k]);
    q.push(nums[i]);
    ans.push_back(q.front());
  }
  return ans;
}
int main() {
  vector<int> nums = {-7, -8, 7, 5, 7, 1, 6, 0};
  maxSlidingWindow(nums, 4);
}