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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;

        int len=0;
        ListNode* temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        k=k%len;
        if(k==0) return head;

        ListNode* st=head;
        for(int i=0;i<(len-k-1);++i) st=st->next;
        
        ListNode* n_head=st->next;
        st->next=NULL;
        st=n_head;
        while(st->next)
        {
            st=st->next;
        }
        st->next=head;
        return n_head;
    }
};