struct ListNode {
  ListNode(int value) : value(value), next(nullptr) {}

  int value;
  ListNode *next;
};

class Solution {
 public:
  ListNode *GetIntersectionNode(ListNode *head_a, ListNode *head_b) {
    ListNode *a = head_a;
    ListNode *b = head_b;
    while (a != b) {
      a = (a != nullptr) ? a->next : head_b;
      b = (b != nullptr) ? b->next : head_a;
    }
    return a;
  }
};