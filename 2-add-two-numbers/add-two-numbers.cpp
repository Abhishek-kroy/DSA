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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* temp=&dummy;

        int carry=0;

        ListNode* t1=l1;        

        while(l1 || l2){
            int v1=l1 ? l1->val:0;
            int v2=l2 ? l2->val:0;

            int sum=v1+v2+carry;

            int num=sum%10;
            carry=sum/10;

            temp->next=new ListNode(num);
            temp=temp->next;  

            l1=l1 ? l1->next:l1;
            l2=l2 ? l2->next:l2;
        }

        if(carry){
            temp->next=new ListNode(carry);        
        }

        return dummy.next;
    }
};