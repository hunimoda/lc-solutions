struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr) {
            if (curr->val == val) {
                prev ? (prev->next = curr->next) : (head = curr->next);
                delete curr;
            } else {
                prev = curr;
            }
            curr = prev ? prev->next : head;
        }
        return head;
    }
};