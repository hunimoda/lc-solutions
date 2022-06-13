struct ListNode {
  int value;
  ListNode *next;

  ListNode() : value(0), next(nullptr) {}
  ListNode(int value) : value(value), next(nullptr) {}
  ListNode(int value, ListNode *next) : value(value), next(next) {}
};

class Solution {
 public:
  ListNode *MiddleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }
};