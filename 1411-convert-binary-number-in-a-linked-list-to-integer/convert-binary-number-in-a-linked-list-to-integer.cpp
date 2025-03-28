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
    int getans(ListNode*t){
        int ans=0;
        ListNode* dummy=t;
        while(dummy){
            ans=ans*2+dummy->val;
            dummy=dummy->next;
        }        
        return ans;
    }
    int getDecimalValue(ListNode* head) {
        ListNode* t=head;
        return getans(t);
    }
};