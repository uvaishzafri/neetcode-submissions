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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size+=1;
            temp=temp->next;
        }
        temp=head;
        if(n==size) return head->next;
        for(int i=0;i<size;i++){
            
            if(i==size-n-1){
                //cout<<temp->val<<" "<<i<<" "<<size;
                if(temp->next->next!=NULL){
                    temp->next=temp->next->next;
                }
                else {
                    temp->next = NULL;
                }
                break;
            }
            temp=temp->next;
        }
        return head;
    
    }
};
