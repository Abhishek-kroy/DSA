/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    bool getans(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        slow=slow->next;
        fast=fast->next->next;

        while(fast && fast->next && slow!=fast){          
            slow=slow->next;
            fast=fast->next->next;
        }

        if(slow!=fast){
            return false;
        }

        return true ; 

    }

public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next){    
            return false;
        }
        return getans(head);   
    }
};