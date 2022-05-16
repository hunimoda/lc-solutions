struct ListNode {
  ListNode(int x) : val(x), next(nullptr) {}
  int val;
  ListNode *next;
};

class Solution {
 public:
  bool HasCycle(ListNode *head) {
    for (ListNode *curr{head}; curr; curr = curr->next) {
      if (curr->val > kNodeValueRange) return true;
      curr->val += 2 * kNodeValueRange + 1;
    }
    return false;
  }

 private:
  static constexpr int kNodeValueRange = 100'000;
};