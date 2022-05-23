struct ListNode {
  ListNode(int x) : val(x), next(nullptr) {}
  int val;
  ListNode *next;
};

class Solution {
 public:
  bool HasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) return true;
    }
    return false;
  }
};