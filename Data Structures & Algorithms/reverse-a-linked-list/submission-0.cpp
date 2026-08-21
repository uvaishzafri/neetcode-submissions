/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        head->next = NULL;
        while (curr) {
            ListNode* nexter = curr->next;

            curr->next = prev;
            if (nexter == NULL) break;
            prev = curr;
            curr = nexter;
            cout << prev->val << endl;
        }
        return curr;
    }
};
