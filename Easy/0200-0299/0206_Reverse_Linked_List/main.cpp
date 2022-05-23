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
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode *reversed = ReverseList(head->next);
    ListNode *end = reversed;
    while (end->next)
      end = end->next;
    head->next = nullptr;
    end->next = head;
    return reversed;
  }
};