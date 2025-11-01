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
    ListNode* getans(unordered_set<int>& s,ListNode* head){
        // move head to value not existing in s
        while(head && s.find(head->val)!=s.end()){
            head=head->next;
        }
        // so head is pointing to a node in modifiedlist 
        ListNode* t=head;
        while(t->next){
            if(s.find(t->next->val)!=s.end()){
                t->next=t->next->next;
            }
            else{
                t=t->next;
            }
        }

        return head;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(),nums.end());
        return getans(s,head);
    }
};