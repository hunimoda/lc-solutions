#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 private:
  ListNode *ReverseList(ListNode *head) {
    ListNode *reverse = nullptr;
    while (head) {
      ListNode *temp = reverse;
      reverse = head;
      head = reverse->next;
      reverse->next = temp;
    }
    return reverse;
  }

  ListNode *GetRightHalf(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast) {
      slow = slow->next;
      fast = fast->next;
      if (fast) fast = fast->next;
    }
    return slow;
  }

 public:
  bool IsPalindrome(ListNode *head) {
    ListNode *right = GetRightHalf(head);

    // Reverse the order of the right half
    right = ReverseList(right);

    // Compare one-by-one the left list & the right list
    ListNode *l_curr = head;
    ListNode *r_curr = right;
    while (r_curr) {
      if (l_curr->val != r_curr->val) {
        // Restore init state
        ReverseList(right);
        return false;
      }
      l_curr = l_curr->next;
      r_curr = r_curr->next;
    }
    // Restore init state
    ReverseList(right);
    return true;
  }
};

int main() {
  ListNode *const head = new ListNode(-1, nullptr);  // Points to dummy node
  ListNode *tail = head;

  std::cout << "List: ";

  while (true) {
    int value;
    std::cin >> value;
    if (value < 0) break;
    tail->next = new ListNode(value, nullptr);
    tail = tail->next;
  }

  std::cout << "\t-> ";
  for (ListNode *curr = head->next; curr; curr = curr->next)
    std::cout << curr->val << ' ';
  std::cout << std::endl;

  Solution solution;
  std::cout << std::boolalpha;
  std::cout << "Is palindrome: " << solution.IsPalindrome(head->next)
            << std::endl;

  return 0;
}