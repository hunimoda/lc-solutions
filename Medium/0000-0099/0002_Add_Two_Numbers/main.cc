struct ListNode {
  int val;
  ListNode *next;

  ListNode() : ListNode(0) {}
  ListNode(int val) : ListNode(val, nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Solution {
 public:
  ListNode *AddTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *result = new ListNode();
    ListNode *current = result;
    int carry = 0;

    while (l1 || l2 || carry) {
      int sum = carry;
      if (l1) sum += l1->val, l1 = l1->next;
      if (l2) sum += l2->val, l2 = l2->next;

      carry = sum / 10;
      sum %= 10;
      current->next = new ListNode(sum);
      current = current->next;
    }

    ListNode *remove = result;
    result = result->next;
    delete remove;

    return result;
  }
};