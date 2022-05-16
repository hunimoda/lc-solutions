struct ListNode {
  ListNode(int value) : value(value), next(nullptr) {}

  int value;
  ListNode *next;
};

class Solution {
 public:
  ListNode *GetIntersectionNode(ListNode *head_a, ListNode *head_b) {
    // Calculate size of each linked lists
    size_t size_a = 0, size_b = 0;
    for (ListNode *temp = head_a; temp; temp = temp->next)
      size_a++;
    for (ListNode *temp = head_b; temp; temp = temp->next)
      size_b++;

    // Move pointer so the two point the same position from the back
    ListNode *curr_a = head_a;
    ListNode *curr_b = head_b;
    if (size_a > size_b) {
      for (size_t i = 0; i < size_a - size_b; i++)
        curr_a = curr_a->next;
    } else {
      for (size_t i = 0; i < size_b - size_a; i++)
        curr_b = curr_b->next;
    }

    // Move two pointers until they point the same node or both nullptr
    while (curr_a != curr_b) {
      curr_a = curr_a->next;
      curr_b = curr_b->next;
    }

    return curr_a;
  }
};