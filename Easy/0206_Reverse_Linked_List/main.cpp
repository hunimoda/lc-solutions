struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *ReverseList(ListNode *head) {
    if (!head) return nullptr;
    ListNode *reversed = ReverseList(head->next);
    ListNode *end = reversed;
    while (end && end->next) {
      end = end->next;
    }
    if (end) {
      end->next = head;
      head->next = nullptr;
    } else {
      reversed = head;
    }
    return reversed;
  }
};