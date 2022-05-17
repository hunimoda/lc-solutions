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
    ListNode *reversed = nullptr;
    while (head) {
      ListNode *prev_reversed = reversed;
      reversed = head;
      head = reversed->next;
      reversed->next = prev_reversed;
    }
    return reversed;
  }
};