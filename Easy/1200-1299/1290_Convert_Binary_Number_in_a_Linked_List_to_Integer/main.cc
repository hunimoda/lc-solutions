struct ListNode {
  int val;
  ListNode *next;

  ListNode() : ListNode(0) {}
  ListNode(int val) : ListNode(val, nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Solution {
 public:
  int GetDecimalValue(ListNode *head) {
    int result = 0;
    for (; head; head = head->next)
      result = (result << 1) + head->val;
    return result;;
  }
};