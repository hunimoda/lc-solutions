struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
 public:
  ListNode *DeleteDuplicates(ListNode *head) {
    if (!head) return head;
    ListNode *curr{head};
    while (curr->next) {
      ListNode *temp{curr->next};
      if (temp->val == curr->val) {
        curr->next = temp->next;
        delete temp;
      } else {
        curr = temp;
      }
    }
    return head;
  }
};
