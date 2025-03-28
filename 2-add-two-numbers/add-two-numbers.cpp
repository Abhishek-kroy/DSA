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
    int len(ListNode* t1){
        int l=0;
        ListNode* h=t1;
        while(h){
            l++;
            h=h->next;
        }
        return l;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* t1=l1;
        ListNode* t2=l2;

        int len1=len(t1);
        int len2=len(t2);
        if(len1>=len2){
            t1=l1;
            t2=l2;
        }
        else{
            t1=l2;
            t2=l1;
        }
        
        ListNode* dummy=new ListNode();
        ListNode* newdummy=dummy;
        int c=0;
        while(t2){
            int v1=t1->val;
            int v2=t2->val;
            int v=(v1+v2+c);
            dummy->next=new ListNode(v%10);
            dummy=dummy->next;
            c=(v)/10;
            t1=t1->next;
            t2=t2->next;
        }
        while(t1){
            int v1=t1->val;
            int v2=0;
            int v=(v1+v2+c);
            dummy->next=new ListNode(v%10);
            dummy=dummy->next;
            c=(v)/10;
            t1=t1->next;
        }
        if(c){
            dummy->next=new ListNode(c);
        }
        return newdummy->next;


        return NULL;

        
        
    }
};