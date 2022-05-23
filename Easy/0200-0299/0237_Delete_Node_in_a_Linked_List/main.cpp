struct ListNode {
  int val;
  ListNode *next;
  ListNode(int val) : val(val), next(nullptr) {}
};

class Solution {
 public:
  void DeleteNode(ListNode *node) {
    ListNode *delete_node = node->next;
    node->val = delete_node->val;
    node->next = delete_node->next;
    delete delete_node;
  }
};