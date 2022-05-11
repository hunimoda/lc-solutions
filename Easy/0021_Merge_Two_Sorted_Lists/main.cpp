struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {

public:
    ListNode *merge_two_lists(ListNode *list1, ListNode * list2) {

        // If the list is empty, return the other list
        if (!list1) return list2;
        if (!list2) return list1;

        // Determine which list comes first
        ListNode *front {
            (list1->val < list2->val) ? list1 : list2
        };
        ListNode *back {
            (list1->val < list2->val) ? list2 : list1
        };
        ListNode *merged { front };

        while (front && back) {
            // Move front pointer to the cut point
            while (front->next != nullptr &&
                    front->next->val <= back->val) {
                front = front->next;
            }
            ListNode *next_back { front->next };

            // Partially sort by moving pointers
            front->next = back;
            front = front->next;
            back = next_back;
        }
        
        return merged;

    }

};