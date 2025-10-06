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
    ListNode* combine(ListNode* l1,ListNode* l2)
    {
        ListNode* head=new ListNode();
        ListNode* tail=head;
        while(l1 && l2)
        {
            if(l1->val<l2->val)
            {
                tail->next=l1;
                l1=l1->next;
            }
            else
            {
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }

        if(l1)
        {
            tail->next=l1;
            l1=l1->next;
        }
        if(l2)
        {
            tail->next=l2;
            l2=l2->next;
        }
        ListNode* new_head=head->next;
        delete head;
        return new_head;
    }
    // Merge Sort on Linked list
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=NULL;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next)
        {
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        ListNode* l1=sortList(head);         // Recursive call to left part
        ListNode* l2=sortList(slow);        // Recursive call to right part
        return combine(l1,l2);
    }
};