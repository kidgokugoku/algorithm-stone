/*
 * @lc app=leetcode->cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode->cn/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (54->12%)
 * Likes:    1337
 * Dislikes: 0
 * Total Accepted:    621->9K
 * Total Submissions: 1->1M
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node->val
 * == val 的节点，并返回 新的头节点 。
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,6,3,4,5,6], val = 6
 * 输出：[1,2,3,4,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [], val = 1
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = [7,7,7,7], val = 7
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 列表中的节点数目在范围 [0, 10^4] 内
 * 1
 * 0
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* ans = head;
    if (ans == nullptr) return ans;
    while (ans->val == val) {
      if (ans->next)
        ans = ans->next;
      else
        return nullptr;
    }
    ListNode* cur = ans;
    while (cur->next != nullptr) {
      if (cur->next->val == val)
        if (cur->next->next != nullptr)
          cur->next = cur->next->next;
        else
          cur->next = nullptr;
      else if (cur->next)
        cur = cur->next;
    };

    return ans;
  }
};
// @lc code=end
